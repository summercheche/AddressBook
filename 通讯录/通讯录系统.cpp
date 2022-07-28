#include<iostream>
using namespace std;
#define MAX 1000

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
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

//1�������ϵ��
void addPerson(Addressbooks* abs) //����ָ�������յ�ַ
{
	//�ж�ͨѶ¼��û����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷�������ӡ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1--�У�2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//�绰
		cout << "������绰���룺" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//��ַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;

		//����ͨѶ¼������
		abs->m_size++;

		//��ӳɹ�
		cout << "��ӳɹ���" << endl;

		system("pause"); //�����������

		system("cls");  //��������
	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼����û���ˣ�û����ʾ��¼Ϊ��
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������  " << abs->personArray[i].m_name << "\t";
			cout << "�Ա�  " << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			//�����ŵ����������ȼ�
			/*if (abs->personArray[i].m_sex == 1)
			{
				cout << "��" << "\t";
			}
			else
			{
				cout << "Ů" << "\t";
			}*/
			cout << "���䣺  " << abs->personArray[i].m_age << "\t";
			cout << "���룺  " << abs->personArray[i].m_phone << "\t";
			cout << "��ַ��  " << abs->personArray[i].m_address << endl;
		}

		system("pause");
		system("cls");
	}
}

//3��ɾ����ϵ��
//3��1 �����ϵ���Ƿ���ڣ������򷵻���ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼  ����2 �Ա�����
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;  //�ҵ��ˣ�����������������е��±��ţ�
		}
	}
	return -1;  //û�ҵ�������-1��
}

//3��2 
//ɾ��ָ������ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);  //û�м�ȡַ��������Ϊabs�Ѿ���Ϊ��ַ������һ�����У�����Ҫ�ټ�ȡַ��
	if (ret != -1)
	{
		//�Ѳ鵽����Ҫ����ɾ������
		for (int i = ret; i < abs->m_size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//����ͨѶ¼�е���Ա��
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//4������ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ����ϵ���Ƿ����ͨѶ¼��
	int ret = isExist(abs, name);
	
	if (ret != -1)
	{
		cout << "������  " << abs->personArray[ret].m_name << "\t";
		cout << "�Ա�  " << (abs->personArray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺  " << abs->personArray[ret].m_age << "\t";
		cout << "�绰��  " << abs->personArray[ret].m_phone << "\t";
		cout << "��ַ��  " << abs->personArray[ret].m_address << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)  //�ҵ�ָ����ϵ��
	{
		//����
		string name;
		cout << "������������  " << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�  " << endl;
		cout << "1--�У�2--Ů " << endl;
		int sex = 0;
		
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		
		//����
		cout << "���������䣺  " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//�绰
		cout << "������绰���룺  " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//��ַ
		cout << "�������ַ��  " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_address = address;
		cout << "�޸ĳɹ���" << endl;
	}
	else  //δ�ҵ���ϵ��
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}


//6�������ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "ȷ��Ҫ�����" << endl;
	cout << "ȷ����������1��" << endl;
	int a = 0;
	cin >> a;
	if (a = 1) 
	{
		abs->m_size = 0;
		cout << "ͨѶ¼�Ѿ���գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ȡ����գ�" << endl;
	}
	system("pause");
	system("cls");
}




int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;
	//�����û�����ı���
	int select = 0; 

	while (true)
	{
		showMenu();
		cout << "������ѡ�" << endl;

		cin >> select;
		switch (select)
		{
		case 1:  //�����ϵ��
			addPerson(&abs); //�ṹ������ĵ�ַ����ȥ��������������ʵ��
			break;

		case 2:  //��ʾ��ϵ��
			showPerson(&abs);
			break;

		case 3:  //ɾ����ϵ��
			deletePerson(&abs);
			break;

		case 4:  //������ϵ��
			findPerson(&abs);
			break;

		case 5:  //�޸���ϵ��
			modifyPerson(&abs);
			break;

		case 6:  //�����ϵ��
			cleanPerson(&abs);
			break;

		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��!" << endl;
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