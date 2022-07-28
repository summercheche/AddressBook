#include<iostream>
using namespace std;
#define MAX 1000

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_address;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size;
};

//1、添加联系人
void addPerson(Addressbooks* abs) //创建指针来接收地址
{
	//判断通讯录有没有满
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法继续添加。" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		
		//性别
		cout << "请输入性别：" << endl;
		cout << "1--男，2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//电话
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//地址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;

		//更新通讯录中人数
		abs->m_size++;

		//添加成功
		cout << "添加成功！" << endl;

		system("pause"); //按任意键继续

		system("cls");  //清屏操作
	}
}

//2、显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中有没有人，没人提示记录为空
	if (abs->m_size == 0)
	{
		cout << "当前记录为空！" << endl;
	}
	//如果不为0，显示记录的联系人信息
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：  " << abs->personArray[i].m_name << "\t";
			cout << "性别：  " << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			//加括号调整运算优先级
			/*if (abs->personArray[i].m_sex == 1)
			{
				cout << "男" << "\t";
			}
			else
			{
				cout << "女" << "\t";
			}*/
			cout << "年龄：  " << abs->personArray[i].m_age << "\t";
			cout << "号码：  " << abs->personArray[i].m_phone << "\t";
			cout << "地址：  " << abs->personArray[i].m_address << endl;
		}

		system("pause");
		system("cls");
	}
}

//3、删除联系人
//3、1 检测联系人是否存在，存在则返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录  参数2 对比姓名
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;  //找到了，返回这个人在数组中的下标编号；
		}
	}
	return -1;  //没找到，返回-1；
}

//3、2 
//删除指定的联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);  //没有加取址符，是因为abs已经作为地址传入这一函数中，不需要再加取址符
	if (ret != -1)
	{
		//已查到，需要进行删除操作
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//更新通讯录中的人员数
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定联系人是否存在通讯录中
	int ret = isExist(abs, name);
	
	if (ret != -1)
	{
		cout << "姓名：  " << abs->personArray[ret].m_name << "\t";
		cout << "性别：  " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：  " << abs->personArray[ret].m_age << "\t";
		cout << "电话：  " << abs->personArray[ret].m_phone << "\t";
		cout << "地址：  " << abs->personArray[ret].m_address << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//5、修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)  //找到指定联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：  " << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		//性别
		cout << "请输入性别：  " << endl;
		cout << "1--男，2--女 " << endl;
		int sex = 0;
		
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		//年龄
		cout << "请输入年龄：  " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//电话
		cout << "请输入电话号码：  " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//地址
		cout << "请输入地址：  " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_address = address;
		cout << "修改成功！" << endl;
	}
	else  //未找到联系人
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}


//6、清空联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "确定要清空吗？" << endl;
	cout << "确定操作输入1。" << endl;
	int a = 0;
	cin >> a;
	if (a = 1) 
	{
		abs->m_size = 0;
		cout << "通讯录已经清空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "已取消清空！" << endl;
	}
	system("pause");
	system("cls");
}




int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;
	//创建用户输入的变量
	int select = 0; 

	while (true)
	{
		showMenu();
		cout << "请输入选项：" << endl;

		cin >> select;
		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs); //结构体变量的地址传进去，才能真正修饰实参
			break;

		case 2:  //显示联系人
			showPerson(&abs);
			break;

		case 3:  //删除联系人
			deletePerson(&abs);
			break;

		case 4:  //查找联系人
			findPerson(&abs);
			break;

		case 5:  //修改联系人
			modifyPerson(&abs);
			break;

		case 6:  //清空联系人
			cleanPerson(&abs);
			break;

		case 0://退出通讯录
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;

		default :
			system("pause");
			system("cls");
			break;
		}
	}
	





	system("pause");
	return 0;
}