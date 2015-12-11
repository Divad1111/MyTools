/**************************************************************
 * 文件名: CommonDef.h
 * 功能说明: 公共的定义
 * 作者：zw
 * 日期：2015/10/17
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/
#include <string>
#include <vector>
#include <map>

#include "plog/Log.h"

//命名空间宏定义
#define BEGIN_NS_SDK namespace Sdk {
#define END_NS_SDK }
#define US_NS_SDK using namespace Sdk


//安全删除指针
#define SAFE_DEL(ptr) { if( (ptr) != nullptr) delete (ptr); }
#define SAFE_DEL_ARRAY (ptr) { if ( (ptr) != nullptr) delete[] (ptr); }

//类型定义
typedef std::vector<std::string> StringArray;






