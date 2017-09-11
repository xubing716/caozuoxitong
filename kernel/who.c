#define  __LIBRARY__
#include <unistd.h>
#include <errno.h>
#include <asm/segment.h>

//实现将用户空间的字符串拷贝到内核空间中
//建立变量存储
char tmp[64]={0}  
int sys_iam(const char * name)
{
   int i = 0;
   //字符串长度不能超过32，放回拷贝的字符串的个数，
   //如果超过32，返回-1，同时将errno置为EINVAL
   while(get_fs_byte(name+i) != '\0')
	{
       i++;
    }
   if(i > 23)
	{
       return -EINVAL;
	}
	i = 0;
	//包括字符串结束符
	while((tmp[i] = get_fs_byte(name+i))!= '\0')
	{
	    i++；
	}
	return i;  //返回实际拷贝的字符串个数
}

//获取sys_iam在内核中存储的字符串
//长度不能超过32
int sys_whoami(char * name,unsigned int size)
{
   int i =0;
   while(tmp[i++] != '\0');
   if(size < i)
	{
        //name的空间小于字符串的长度，返回-1
		return -1;
	}
   i = 0;
   //拷贝到用户空间
   while(tmp[i] != '\0')
	{
       put_fs_byte(temp[i],(name + i));
	   i++;
    }
	return i;
}