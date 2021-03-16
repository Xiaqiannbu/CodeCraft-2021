#ifndef INCLUDE_FUNCTION
#define INCLUDE_FUNCTION

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif // !#ifndef INCLUDE_STRING

#ifndef INCLUDE_UNORDERED_MAP
#include <unordered_map>
#define INCLUDE_UNORDERED_MAP
#endif // !INCLUDE_UNORDERED_MAP

#ifndef INCLUDE_VECTOR
#include <vector>
#define INCLUDE_VECTOR
#endif // !INCLUDE_VECTOR

#ifndef INCLUDE_TIME
#include <time.h>
#define INCLUDE_TIME
#endif // !INCLUDE_TIME

#ifndef INCLUDE_ALGORITHM
#include <algorithm>
#define INCLUDE_ALGORITHM
#endif // !INCLUDE_ALGORITHM

#ifndef INCLUDE_ASSERT
#include <assert.h>
#define INCLUDE_ASSERT
#endif // !INCLUDE_ASSERT

using namespace std;

// 服务器信息
class Server
{
public:
	void generateServer(string& serverType, string& cpuCores,\
		string& memorySize, string& serverCost, string& powerCost);
	// 尝试在服务器上分配虚拟机资源
	bool choseServer(vector<int>& server, vector<int>& vm, int serverId, string vmId);
	// 初始化server，如何初始化购买的服务器是一个大的优化
	void bugServer();
	//总分配策略
	void matchTotal();
	//统计能耗成本
	void serverPower();
	void setVMInfos(unordered_map<string, vector<int>> vmInfos) { this->vmInfos = vmInfos; };
	void setRequestInfos(vector<vector<vector<string>>> totalRequestInfos)\
		{ this->totalRequestInfos = totalRequestInfos; }

private:
	// 服务器信息
	unordered_map<string, vector<int>> serverInfos;
	// 购买的服务器信息
	int serverNumber = 0;
	unordered_map<int, vector<int>> sysServerResource;
	// 当前开机服务器
	vector<int> serverRunVms;
	// 记录虚拟机运行在那个服务器上
	unordered_map<string, vector<int>> vmOnServer;
	long long serverCost = 0, powerCost = 0, totalCost = 0;
	int daysNum = 0;
	// 虚拟机信息
	unordered_map<string, vector<int>> vmInfos;
	// 总请求信息
	vector<vector<vector<string>>> totalRequestInfos;
	// 当天请求信息
	vector<vector<string>> requestInfos;

private:
	// 处理创建虚拟机操作
	int createVM(vector<string>& createVmInfo);
	// 处理删除虚拟机操作
	void delVM(vector<string>& delVmInfo);
	// 分配策略
	void match(int day);
	// 扩容服务器策略
	void expansion();
	// 迁移虚拟机策略
	void migrate();
};

//虚拟机信息
class VM
{
public:
	void generateVm(string& vmType, string& vmCpuCores, string& vmMemory, string& vmTwoNodes);
	inline unordered_map<string, vector<int>> getVMInfo() { return vmInfos; };

private:
	// 虚拟机信息
	unordered_map<string, vector<int>> vmInfos;
	// 当前开机服务器
	vector<int> serverRunVms;
	// 记录虚拟机运行在那个服务器上
	unordered_map<string, vector<int>> vmOnServer;

private:


};

//请求信息
class Request
{
public:
	// 解析用户添加请求
	void generateRequest(string& op, string& reqVmType, string& reqId);
	// 解析用户删除请求
	void generateRequest(string& op, string& reqId);
	// 将当天请求添加至总请求
	void addRequests();
	inline vector<vector<vector<string>>> getTotalRequestInfos() { return totalRequestInfos; };

private:
	// 当天请求信息
	vector<vector<string>> requestInfos;
	// 总请求信息
	vector<vector<vector<string>>> totalRequestInfos;

private:
	
};

//中央处理
class  CenterProcess
{
public:
	 CenterProcess();
	~ CenterProcess();

private:
	void inputData();
	//void outputData();
	void process();

private:
	Server* server;
	VM* vm;
	Request* request;
};

#endif // !INCLUDE_FUNCTION