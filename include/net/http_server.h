#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
#include"util/base_def.h"
#include"evpp/http/http_server.h"
#include"net/context.h"
namespace luckyDaily
{
	typedef std::shared_ptr<evpp::http::Server> HTTPSvrPtr;
	class LF_DLL_API http_server
	{
	public:
		http_server(const uint32_t& thread_num);
		~http_server();
		bool Init(int listen_port);
		bool Init(const std::vector<int>& listen_ports);
		bool Init(const std::string& listen_ports/*like "80,8080,443"*/);

		bool Start();

		void Stop();

		void Pause();
		void Continue();

		// @brief Reinitialize the event_base object after a fork
		void AfterFork();
		bool IsRunning();
	public:
		void RegisterHandler(const std::string& uri,
			HTTPRequestCB callback);

		void RegisterDefaultHandler(HTTPRequestCB callback);
	private:
		HTTPSvrPtr _svr;
	};
}
#endif // !HTTP_SERVER_H

