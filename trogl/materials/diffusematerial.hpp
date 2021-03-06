#ifndef __DIFFUSE_MATERIAL_HPP__
#define __DIFFUSE_MATERIAL_HPP__


#include "core/material.hpp"


class DiffuseMaterial : public Material
{
	public:
		// Constructors / Destructor.
		DiffuseMaterial(const Color& color,
						const float& diffuse = 1.0,
						const float& specular = 0.5,
						const float& hardness = 7.0);
		DiffuseMaterial(const DiffuseMaterial& mat);
		DiffuseMaterial(DiffuseMaterial&& mat);
		~DiffuseMaterial();

		// Operators.
		DiffuseMaterial& operator=(const DiffuseMaterial& mat);
		DiffuseMaterial& operator=(DiffuseMaterial&& mat);

		DiffuseMaterial& operator+=(const DiffuseMaterial& mat);
		DiffuseMaterial& operator*=(const float& ratio);
		DiffuseMaterial operator+(const DiffuseMaterial& mat) const;
		DiffuseMaterial operator*(const float& ratio) const;

		// Methods.
		const float& getDiffuse() const;
		const float& getSpecular() const;
		const float& getHardness() const;

		void setDiffuse(const float& diffuse);
		void setSpecular(const float& specular);
		void setHardness(const float& hardness);

		// Overriden methods.
		void use() override;

	private:
		float _diffuse;
		float _specular;
		float _hardness;
};


#endif // __DIFFUSE_MATERIAL_HPP__
