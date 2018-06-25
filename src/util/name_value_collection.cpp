#include"util/name_value_collection.h"
namespace LF
{
	std::string name_value_collection::DEFAULT_VALUE = "default value!";
	name_value_collection::name_value_collection()
	{
	}


	name_value_collection::name_value_collection(const name_value_collection& nvc) :
		_map(nvc._map)
	{
	}


	name_value_collection::~name_value_collection()
	{
	}


	name_value_collection& name_value_collection::operator = (const name_value_collection& nvc)
	{
		if (&nvc != this)
		{
			_map = nvc._map;
		}
		return *this;
	}


	void name_value_collection::swap(name_value_collection& nvc)
	{
		std::swap(_map, nvc._map);
	}


	std::string name_value_collection::operator [] (const std::string& name) const
	{
		ConstIterator it = _map.find(name);
		if (it != _map.end())
			return it->second;
		else
			return DEFAULT_VALUE;
	}


	void name_value_collection::set(const std::string& name, const std::string& value)
	{
		Iterator it = _map.find(name);
		if (it != _map.end())
			it->second = value;
	}


	void name_value_collection::add(const std::string& name, const std::string& value)
	{
		_map.insert(std::make_pair(name, value));
	}


	std::string name_value_collection::get(const std::string& name) const
	{
		ConstIterator it = _map.find(name);
		if (it != _map.end())
			return it->second;
		else
			return DEFAULT_VALUE;
	}


	const std::string& name_value_collection::get(const std::string& name, const std::string& defaultValue) const
	{
		ConstIterator it = _map.find(name);
		if (it != _map.end())
			return it->second;
		else
			return defaultValue;
	}


	bool name_value_collection::has(const std::string& name) const
	{
		return _map.find(name) != _map.end();
	}


	name_value_collection::ConstIterator name_value_collection::find(const std::string& name) const
	{
		return _map.find(name);
	}


	name_value_collection::ConstIterator name_value_collection::begin() const
	{
		return _map.begin();
	}


	name_value_collection::ConstIterator name_value_collection::end() const
	{
		return _map.end();
	}


	bool name_value_collection::empty() const
	{
		return _map.empty();
	}


	std::size_t name_value_collection::size() const
	{
		return _map.size();
	}


	void name_value_collection::erase(const std::string& name)
	{
		_map.erase(name);
	}


	void name_value_collection::clear()
	{
		_map.clear();
	}

}