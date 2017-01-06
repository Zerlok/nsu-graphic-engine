#ifndef __MESH_HPP__
#define __MESH_HPP__


#include <vector>
#include <list>
#include <unordered_map>
#include <glm/glm.hpp>
#include <sharedpointer.h>
#include "common/color.hpp"
#include "material.hpp"
#include "object.hpp"


class Mesh : public Object
{
	public:
		// Static.
		static const MaterialPtr DEFAULT_MATERIAL;

		// Inner classes.
		// TODO: write function which returns indicies for IBO by indexing type.
		enum IndexingType
		{
			TRIANGLES = GL_TRIANGLES,
			// TRIANGLES_STRIP = GL_TRIANGLE_STRIP,
		};

		class Vertex;
		class Polygon;

		class Triple
		{
			public:
				// Inner classes.
				class Hash
				{
					public:
						size_t operator()(const Triple& p) const;
				};

				// Constructors / Destructor.
				Triple(const size_t& i1,
					   const size_t& i2,
					   const size_t& i3);
				Triple(const Triple& tr);
				Triple(Triple&& tr);
				~Triple();

				// Operators.
				Triple& operator=(const Triple& tr);
				Triple& operator=(Triple&& tr);

				bool operator==(const Triple& tr) const;
				bool operator!=(const Triple& tr) const;
				bool operator<(const Triple& tr) const;

				// Methods.
				size_t getFirst() const;
				size_t getSecond() const;
				size_t getThird() const;

			private:
				// Fields.
				size_t idx1;
				size_t idx2;
				size_t idx3;

				// Friend classes.
				friend class Vertex;
				friend class Polygon;
		};

		class Vertex
		{
			public:
				// Constructors / Destructor.
				Vertex(const float& x,
					   const float& y,
					   const float& z,
					   const float& nx,
					   const float& ny,
					   const float& nz,
					   const float& u,
					   const float& v,
					   Mesh* mesh = nullptr);
				Vertex(const vec& position,
					   const vec& normal,
					   const glm::vec2& uv,
					   Mesh* mesh = nullptr);
				Vertex(const Vertex& v);
				Vertex(Vertex&& v);
				~Vertex();

				// Operators.
				Vertex& operator=(const Vertex& v);
				Vertex& operator=(Vertex&& v);

				// Methods.
				const size_t& getIndex() const;
				const vec& getPosition() const;
				const vec& getNormal() const;
				const glm::vec2& getUV() const;

				vec calculateNormal() const;

				void setPosition(const glm::vec3& pos);
				void setNormal(const glm::vec3& nor);
				void setUV(const glm::vec2& uv);

			private:
				// Fields.
				size_t _idx;
				Object::vec _position;
				Object::vec _normal;
				glm::vec2 _uv;

				std::vector<Triple> _linkedTriples; // Aggregation links with Polygons.
				Mesh* _linkedMesh;

				// Friend classes.
				friend class Mesh;
				friend class Polygon;
		};

		class Polygon
		{
			public:
				// Constructors / Destructor.
				Polygon(const size_t& i1,
						const size_t& i2,
						const size_t& i3,
						Mesh* mesh = nullptr);
				Polygon(const Triple& tr,
						Mesh* mesh = nullptr);
				Polygon(const Polygon& p);
				Polygon(Polygon&& p);
				~Polygon();

				// Operators.
				Polygon& operator=(const Polygon& p);
				Polygon& operator=(Polygon&& p);

				bool operator==(const Polygon& p) const;
				bool operator!=(const Polygon& p) const;

				// Methods.
				const size_t& getIdx1() const;
				const size_t& getIdx2() const;
				const size_t& getIdx3() const;

				const Vertex& getV1() const;
				const Vertex& getV2() const;
				const Vertex& getV3() const;

				Vertex& getV1();
				Vertex& getV2();
				Vertex& getV3();

				vec calculateNormal() const;
				vec calculateCenter() const;
				void flip();

			private:
				// Fields.
				Triple _triple;
				Mesh* _linkedMesh; // Association link with Mesh.

				void _linkVertices();
				void _unlinkVertices();

				// Friends classes.
				friend class Mesh;
				friend class Vertex;
		};

		using Vertices = std::vector<Vertex>;
		using Polygons = std::unordered_map<Triple, Polygon, Triple::Hash>;

		// Constructors / Destructor.
		Mesh(const std::string& name = std::string(),
			 const MaterialPtr& mat = Mesh::DEFAULT_MATERIAL,
			 const IndexingType& indexType = IndexingType::TRIANGLES);
		Mesh(const Mesh& mesh);
		Mesh(Mesh&& mesh);
		virtual ~Mesh();

		// Operators.
		Mesh& operator=(const Mesh& mesh);
		Mesh& operator=(Mesh&& mesh);

		// Methods.
		Vertex& getVertex(const size_t& i);
		const Vertex& getVertex(const size_t& i) const;
		const Polygon& getPolygon(const size_t& i1,
								  const size_t& i2,
								  const size_t& i3) const;
		const Polygon& getPolygon(const Triple& tr) const;
		const Vertices& getVertices() const;
		const Polygons& getPolygons() const;
		const MaterialPtr& getMaterial() const;
		const IndexingType& getIndexType() const;

		size_t addVertex(const float& x,
						 const float& y,
						 const float& z,
						 const float& nx = 0.0f,
						 const float& ny = 0.0f,
						 const float& nz = 0.0f,
						 const float& u = 0.0f,
						 const float& v = 0.0f);
		size_t addUVVertex(const float& x,
						   const float& y,
						   const float& z,
						   const float& u = 0.0f,
						   const float& v = 0.0f);
		size_t addVertex(const Vertex& v);
		bool addPolygon(const size_t& i1,
						const size_t& i2,
						const size_t& i3);
		bool addPolygon(const Triple& tr);
		bool addPolygon(const Polygon& p);

		// void removeVertex();
		// void removePolygon();
		void setMaterial(const MaterialPtr& material);

		void recalculateNormals();

		void applyPosition() override;
		void applyRotation() override;
		void applyScale() override;

	protected:
		// Fields.
		Vertices _vertices;
		Polygons _polygons;
		MaterialPtr _material;
		IndexingType _indexType;

		// Methods.
		void _reassignData();
};

using MeshPtr = SharedPointer<Mesh, Object>;
using Meshes = std::list<MeshPtr>;


#endif // __MESH_HPP__
