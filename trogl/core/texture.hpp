#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__


#include <vector>
#include <sharedpointer.h>
#include "opengls.hpp"
#include "component.hpp"


class Texture : public Component
{
	public:
		// Constructors / Destructor.
		Texture(const std::string& name);
		virtual ~Texture();

		// Methods.
		const glm::vec2& getUVOffset() const;
		const float& getColorMix() const;
		const float& getNormal() const;
		const size_t& getSampler() const;

		void bind();
		void unbind();

		// Virtual methods.
		virtual void generate();

	protected:
		// Fields.
		size_t _id;
		GLuint _glTexture;
		glm::vec2 _uvOffset;
		float _colorMix;
		float _normal;

	private:
		static size_t textureID;
};

using TexturePtr = SharedPointer<Texture, Component>;
using Textures = std::vector<TexturePtr>;


#endif // __TEXTURE_HPP__
