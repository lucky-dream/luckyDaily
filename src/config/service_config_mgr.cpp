#include"config/service_config_mgr.h"
#include <fstream>
#include"rapidjson/document.h"


#ifndef _CHECK_JSON
#define _CHECK_JSON(Doc,Key,Type) (((Doc).HasMember(Key)?true:false)&&(Doc)[Key].Is##Type())
#endif // !_CHECK_JSON
namespace luckyDaily
{
	OBJ_SINGLETON_INIT(service_config_mgr);
	service_config_mgr g_service_config_mgr;
	rapidjson::Document doc;

	bool service_config_mgr::read_config_file(const string & path)
	{
		std::ifstream fd(path, std::ios::out | std::ios::binary | std::ios::ate);
		if (!fd.is_open())
		{
			return false;
		}
		int count = fd.tellg();
		char* m_data = new char[count + 1];
		fd.seekg(0, std::ios::beg);
		fd.read(m_data, count);
		m_data[count] = '\0';
		int m_data_len = count + 1;
		_config.assign(m_data,count);
		delete[]m_data;
		doc.Parse(_config.c_str(),_config.length());
		if (doc.HasParseError())
		{
			_config.clear();
			return false;
		}
		return true;
	}

	string service_config_mgr::get_value(const string & key)
	{
		if (doc.HasParseError())
		{
			_config.clear();
			return false;
		}
		if (_CHECK_JSON(doc, key.c_str(), String))
		{
			return doc[key.c_str()].GetString();
		}
		return string();
	}

}