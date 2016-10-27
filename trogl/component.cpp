#include "component.hpp"


#include <sstream>
#include <iomanip>
#include <logger.hpp>


loggerModules lModules = loggerForModule(Logger::Level::DEBUG, Logger::Description::FULL);


size_t Component::_globID = 0;


Component::Component(const Component::Type& t,
					 const std::string& name)
	: _type(t),
	  _ID(++_globID),
	  _name(name)
{
	if (_name.empty())
		_name = _generateNameFromType(_type, _ID);

	logModule << (*this) << " created" << logEndl;
}


Component::Component(const Component& c)
	: _type(c._type),
	  _ID(c._ID),
	  _name(c._name)
{
	logModule << (*this) << " copied from " << c << logEndl;
}


Component::Component(Component&& c)
	: _type(std::move(c._type)),
	  _ID(std::move(c._ID)),
	  _name(std::move(c._name))
{
	logModule << "Component " << (*this) << " moved" << logEndl;
}


Component::~Component()
{
	logModule << "Component " << (*this) << " deleted" << logEndl;
}


Component& Component::operator=(const Component& c)
{
	_type = c._type;
	_ID = c._ID;
	_name = c._name;

	return (*this);
}


Component& Component::operator=(Component&& c)
{
	_type = std::move(c._type);
	_ID = std::move(c._ID);
	_name = std::move(c._name);

	return (*this);
}


bool Component::operator==(const Component& c) const
{
	return (_ID == c._ID);
}


bool Component::operator!=(const Component& c) const
{
	return (!this->operator==(c));
}


const Component::Type& Component::getType() const
{	
	return _type;
}


const std::string& Component::getName() const
{
	return _name;
}


void Component::setName(const std::string& name)
{
	_name = name;
}


Component Component::copy() const
{
	Component c(*this);
	c._ID = ++_globID;
	c._name = _generateNameFromCopy(c);

	return std::move(c);
}


std::string Component::toString() const
{
	std::stringstream ss;
	ss << _name;
	return std::move(ss.str());
}


std::ostream& operator<<(std::ostream& out, const Component& c)
{
	out << "<Component:"
		<< &c << " '"
		<< c._name << "'>";

	return out;
}


std::string Component::_generateNameFromType(const Type& type,
											const size_t& id)
{
	std::stringstream ss;
	switch (type)
	{
		case Type::GUI:
			ss << "GUI";
			break;
		case Type::SCENE:
			ss << "Scene";
			break;
		case Type::OBJECT:
			ss << "Object";
			break;
		case Type::MATERIAL:
			ss << "Material";
			break;
		case Type::TEXTURE:
			ss << "Texture";
			break;
		case Type::SHADER:
			ss << "Shader";
			break;
		default:
			break;
	}

	ss << std::setw(3) << std::setfill('0') << id;

	return ss.str();
}


std::string Component::_generateNameFromCopy(const Component& c)
{
	std::stringstream ss;
	ss << c.getName() << ".copy";
	return ss.str();
}
