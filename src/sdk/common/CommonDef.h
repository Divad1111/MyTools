/**************************************************************
 * �ļ���: CommonDef.h
 * ����˵��: �����Ķ���
 * ���ߣ�zw
 * ���ڣ�2015/10/17
 * �޸ļ�¼
 * -------------------------------------------------------------
 * �޸ļ�¼ :
  ����       �汾    ����    ����
 **************************************************************/
#include <string>
#include <vector>
#include <map>

#include "plog/Log.h"

//�����ռ�궨��
#define BEGIN_NS_SDK namespace Sdk {
#define END_NS_SDK }
#define US_NS_SDK using namespace Sdk


//��ȫɾ��ָ��
#define SAFE_DEL(ptr) { if( (ptr) != nullptr) delete (ptr); }
#define SAFE_DEL_ARRAY (ptr) { if ( (ptr) != nullptr) delete[] (ptr); }

//���Ͷ���
typedef std::vector<std::string> StringArray;






