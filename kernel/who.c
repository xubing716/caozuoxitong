#define  __LIBRARY__
#include <unistd.h>
#include <errno.h>
#include <asm/segment.h>

//ʵ�ֽ��û��ռ���ַ����������ں˿ռ���
//���������洢
char tmp[64]={0}  
int sys_iam(const char * name)
{
   int i = 0;
   //�ַ������Ȳ��ܳ���32���Żؿ������ַ����ĸ�����
   //�������32������-1��ͬʱ��errno��ΪEINVAL
   while(get_fs_byte(name+i) != '\0')
	{
       i++;
    }
   if(i > 23)
	{
       return -EINVAL;
	}
	i = 0;
	//�����ַ���������
	while((tmp[i] = get_fs_byte(name+i))!= '\0')
	{
	    i++��
	}
	return i;  //����ʵ�ʿ������ַ�������
}

//��ȡsys_iam���ں��д洢���ַ���
//���Ȳ��ܳ���32
int sys_whoami(char * name,unsigned int size)
{
   int i =0;
   while(tmp[i++] != '\0');
   if(size < i)
	{
        //name�Ŀռ�С���ַ����ĳ��ȣ�����-1
		return -1;
	}
   i = 0;
   //�������û��ռ�
   while(tmp[i] != '\0')
	{
       put_fs_byte(temp[i],(name + i));
	   i++;
    }
	return i;
}