#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__


#include "opengls.hpp"
#include "object.hpp"
#include "shader.hpp"
#include "material.hpp"
#include "mesh.hpp"
#include "light.hpp"
#include "camera.hpp"


class Primitive
{
	public:
		// Constructors / Destructor.
		Primitive(const MeshPtr& mesh);
		Primitive(Primitive&& obj);
		~Primitive();

		// Methods.
		bool isValid() const;
		void compileGLShaders();
		void initGLGeometry(const MeshPtr& mesh);

		void draw(const LightPtr& light, const CameraPtr& camera);

	private:
		// Static fields.
		static const size_t _vertexStep;
		static const size_t _indexStep;

		// OpenGL attributes.
		GLuint _glVBO; // Vertex Buffer Object
		GLuint _glNBO; // Vertex Normal Buffer Object
		GLuint _glIBO; // Index Buffer Object

		Mesh::IndexingType _indexType;
		size_t _indicesSize;
		Object::vec _position;
		MaterialPtr _material;
		ShaderPtr _shader;

		// Methods.
		bool _isGLGeometryValid() const;

		void _initVertexBufferObject(const MeshPtr& mesh);
		void _initIndexBufferObject(const MeshPtr& mesh);
		void _deinitGLGeometry();
};


#endif // __PRIMITIVE_HPP__