#ifndef __SCENE_HPP__
#define __SCENE_HPP__


#include <string>
#include <list>

#include "common/color.hpp"

#include "object.hpp"
#include "mesh.hpp"
#include "lamp.hpp"
#include "camera.hpp"


using Objects = std::list<Object*>;
using Meshes = std::list<Mesh>;
using Lamps = std::list<Lamp>;


class Scene : public Component
{
	public:
		Scene(const std::string& name = std::string(),
			  const Camera& camera = DEFAULT_CAMERA);
		~Scene();

		void addMesh(const Mesh& mesh);
		void addLamp(const Lamp& lamp);

		const Objects& getObjects() const;
		const Meshes& getMeshes() const;
		const Lamps& getLamps() const;

		const Camera& getCamera() const;
		void setCamera(const Camera& camera);

		const Color& getBgColor() const;
		void setBgColor(const Color& color);

	private:
		static const std::string DEFAULT_NAME;
		static const Camera DEFAULT_CAMERA;

		Objects _objects;
		Meshes _meshes;
		Lamps _lamps;
		Camera _camera;

		Color _bgColor;
};


#endif // __SCENE_HPP__
