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

// ��������Ϣ
class Server
{
public:
	void generateServer(string& serverType, string& cpuCores,\
		string& memorySize, string& serverCost, string& powerCost);
	// �����ڷ������Ϸ����������Դ
	bool choseServer(vector<int>& server, vector<int>& vm, int serverId, string vmId);
	// ��ʼ��server����γ�ʼ������ķ�������һ������Ż�
	void bugServer();
	//�ܷ������
	void matchTotal();
	//ͳ���ܺĳɱ�
	void serverPower();
	void setVMInfos(unordered_map<string, vector<int>> vmInfos) { this->vmInfos = vmInfos; };
	void setRequestInfos(vector<vector<vector<string>>> totalRequestInfos)\
		{ this->totalRequestInfos = totalRequestInfos; }

private:
	// ��������Ϣ
	unordered_map<string, vector<int>> serverInfos;
	// ����ķ�������Ϣ
	int serverNumber = 0;
	unordered_map<int, vector<int>> sysServerResource;
	// ��ǰ����������
	vector<int> serverRunVms;
	// ��¼������������Ǹ���������
	unordered_map<string, vector<int>> vmOnServer;
	long long serverCost = 0, powerCost = 0, totalCost = 0;
	int daysNum = 0;
	// �������Ϣ
	unordered_map<string, vector<int>> vmInfos;
	// ��������Ϣ
	vector<vector<vector<string>>> totalRequestInfos;
	// ����������Ϣ
	vector<vector<string>> requestInfos;

private:
	// ���������������
	int createVM(vector<string>& createVmInfo);
	// ����ɾ�����������
	void delVM(vector<string>& delVmInfo);
	// �������
	void match(int day);
	// ���ݷ���������
	void expansion();
	// Ǩ�����������
	void migrate();
};

//�������Ϣ
class VM
{
public:
	void generateVm(string& vmType, string& vmCpuCores, string& vmMemory, string& vmTwoNodes);
	inline unordered_map<string, vector<int>> getVMInfo() { return vmInfos; };

private:
	// �������Ϣ
	unordered_map<string, vector<int>> vmInfos;
	// ��ǰ����������
	vector<int> serverRunVms;
	// ��¼������������Ǹ���������
	unordered_map<string, vector<int>> vmOnServer;

private:


};

//������Ϣ
class Request
{
public:
	// �����û��������
	void generateRequest(string& op, string& reqVmType, string& reqId);
	// �����û�ɾ������
	void generateRequest(string& op, string& reqId);
	// ���������������������
	void addRequests();
	inline vector<vector<vector<string>>> getTotalRequestInfos() { return totalRequestInfos; };

private:
	// ����������Ϣ
	vector<vector<string>> requestInfos;
	// ��������Ϣ
	vector<vector<vector<string>>> totalRequestInfos;

private:
	
};

//���봦��
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