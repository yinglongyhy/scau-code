#include "Library.h"

bool BuildRoot(Link *head)//创建管理员密码
{
	string password1, password2;
	cout << right << setw(LENGHT) << " " << "请输入新建管理员密码:";
	system("stty -echo");
	cin >> password1;
	system("stty echo");
	cout << endl;
	cout << right << setw(LENGHT) << " " << "请再次输入新建管理员密码:";
	system("stty -echo");
	cin >> password2;
	system("stty echo");
	cout << endl;
	if(password1 == password2) 
	{
		head->ISBN = password1;
		cout << right << setw(LENGHT) << " " << "管理员密码创建成功" << endl;
		return true;
	}
	cout << right << setw(LENGHT) << " " << "管理员密码创建失败，请重新输入" << endl;
	return false;
	
}

bool ResetRoot(Link *head) //重设管理员密码
{
	if(!IsRoot(head)) return false;
	BuildRoot(head);
	return true;
}

void EncryptedRoot(Link *head) //加密管理员密码
{
	for(int i = 0; i < (int)head->ISBN.length(); i++)
		head->ISBN[i] = (head->ISBN[i] + 128 * 100 - (i + 1) * (i + 3)) % 128;
}

void DecryptedRoot(Link *head) //解密管理员密码
{
	for(int i = 0; i < (int)head->ISBN.length(); i++)
		head->ISBN[i] = (head->ISBN[i] + (i + 1) * (i + 3)) % 128;
}

bool LinkCreat(Link *head) //创建链表
{
    Link *q = NULL;
    string ISBN;
    string bookname;
    string writer;
    string publisher;
    string date;
    int price;
    while(1)
    {
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
        cout << right << setw(LENGHT) << " " << "请输入ISBN码: （输入'#'结束输入）";
        cin >> ISBN;
        if(ISBN == "#") return true;
        cout << right << setw(LENGHT) << " " << "请输入书名:";
        cin >> bookname;
        cout << right << setw(LENGHT) << " " << "请输入作者:";
        cin >> writer;
        cout << right << setw(LENGHT) << " " << "请输入出版社名称:";
        cin >> publisher;
        cout << right << setw(LENGHT) << " " << "请输入书籍藏书日期:";
        cin >> date;
        cout << right << setw(LENGHT) << " " << "请输入书籍价格:";
        cin >> price;
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		cout << endl;
        q = new Link;
        if(q == NULL) 
        {
            cout << right << setw(LENGHT) << " " << "空间不足，无法创建" << endl;
            return false;
        }
        q->ISBN = ISBN;
        q->bookname = bookname;
        q->writer = writer;
        q->publisher = publisher;
        q->date = date;
        q->price = price;
        q->next = NULL;
		LinkInsert(head, q);
    }
	return true;
}

bool IsRoot(Link *head) //判断是否管理员
{
	string password;
	cout << right << setw(LENGHT) << " " << "请输入管理员密码："; 
	system("stty -echo");
	cin >> password;
	system("stty echo");
	cout << endl;
	if(head->ISBN == password) return true;
	cout << right << setw(LENGHT) << " " << "密码错误" << endl; 
	return false;
}

bool LinkInsert(Link *head, Link *q) //插入图书信息
{
	if(!head) return false;
	if(!head->next) head->next = q;//没结点
	else if(q->ISBN <= head->next->ISBN) //只有一个结点并且新结点ISBN小于等于头结点
	{
		if(q->ISBN == head->next->ISBN) return false;
		q->next = head->next;
		head->next = q;
	}
	else
	{
		Link *p = head->next;
		while(p->next && p->next->ISBN <= q->ISBN) 
		{
			if(p->ISBN == head->next->ISBN) return false; 
			p = p->next;
		}
		q->next = p->next;
		p->next = q;
	}
	return true;
}

bool LinkInput(Link *q)  //输入书籍信息
{
    if(!q)
    {
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
        cout << right << setw(LENGHT) << " " << "内存不足，插入失败" << endl << endl;
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		cout << endl;
		return false;
    }
	string temp;
	int price;
	
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
    cout << right << setw(LENGHT) << " " << "请输入ISBN码:";
    cin >> temp;
    //cin >> q->ISBN;
	q->ISBN = temp;
    cout << right << setw(LENGHT) << " " << "请输入书名:";
    cin >> temp;
	q->bookname = temp;
    //cin >> q->bookname;
    cout << right << setw(LENGHT) << " " << "请输入作者:";
    cin >> temp;
	q->writer = temp;
    //cin >> q->writer;
    cout << right << setw(LENGHT) << " " << "请输入出版社名称:";
    cin >> temp;
	q->publisher = temp;
    //cin >> q->publisher;
    cout << right << setw(LENGHT) << " " << "请输入书籍藏书日期:";
    cin >> temp;
	q->date = temp;
    //cin >> q->date;
    cout << right << setw(LENGHT) << " " << "请输入书籍价格:";
    cin >> price;
	q->price = price;
	q->next = NULL;
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	cout << endl;
    return true;
} 

bool Linkdelete(Link *head) //删除图书
{
	if(!head) return false;
    Link *p = LinkfindByISBN(head); 
    if(!p) return false;
    Link *q = p->next;
    p->next = q->next;
    q->next = NULL;
    free(q);
    q = NULL;
    return true;
}

bool LinkChange(Link *head) //修改图书信息
{
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	if(!head) return false;
	Link *p = LinkfindByISBN(head);
	if(!p) 
	{
		cout << right << setw(LENGHT) << " " << "无该图书" << endl;
		return false;
	}
	Link *q = p->next;
	p->next = q->next;
	Link *t = new Link;
	LinkInput(t);
	if(!LinkInsert(head, t)) 
	{
		LinkInsert(head, q);
		free(t);
		t = NULL;
		cout << right << setw(LENGHT) << " " << "已有该图书, 修改失败" << endl;
		return false;
	}
	free(q);
	q = NULL;
	cout << right << setw(LENGHT) << " " << "修改成功" << endl;
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl << endl;
    return true;
}

int ISBNOrNameOrPublisher() //ISBN为1  Name为2 Publisher为3
{
    int choice;
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
    cout << right << setw(LENGHT) << " " << "请选择查找方式" << endl;
	cout << right << setw(LENGHT) << " " << "1、ISBN" << endl;
	cout << right << setw(LENGHT) << " " << "2、书名" << endl;
	cout << right << setw(LENGHT) << " " << "3、出版社" << endl;
	cout << right << setw(LENGHT) << " ";
    cin >> choice;
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
    return choice;
}

Link *LinkfindByISBN(Link *head) //通过ISBN查找图书位置的前驱
{
    Link *p = head;
    string ISBN;
    cout << right << setw(LENGHT) << " " << "请输入ISBN编号：";
    cin >> ISBN;
    while(p->next && ISBN >= p->next->ISBN)
    {
        if(p->next->ISBN == ISBN) return p;
        p = p->next;
    }
    return NULL;
}

Link *LinkfindByName(Link *head, string &name) //通过字符串查找所有书名中包括该字符串的图书的信息的前驱
{
    Link *p = head;
    while(p->next)
    {
        if(p->next->bookname.find(name) != string::npos) return p;
        p = p->next;
    }
    return NULL;
}

Link *LinkfindByPublisher(Link *head, string &publisher) //通过出版社名称查找书籍的前驱
{
    Link *p = head;
    while(p->next)
    {
        if(p->next->publisher.find(publisher) != string::npos) return p;
        p = p->next;
    }
    return NULL;
}

bool BookPrint(Link *p) //打印图书信息
{
	if(!p) return false;
	cout << right << setw(LENGHT) << " " << "ISBN：" << p->ISBN << endl;
	cout << right << setw(LENGHT) << " " << "书名：" << p->bookname << endl;
	cout << right << setw(LENGHT) << " " << "作者：" << p->writer << endl;
	cout << right << setw(LENGHT) << " " << "出版社：" << p->publisher << endl;
	cout << right << setw(LENGHT) << " " << "藏书日期：" << p->date << endl;
	cout << right << setw(LENGHT) << " " << "价格：" << p->price << endl;
	cout << endl;
	return true;   
}

bool BookShow(Link *head) //显示合适的图书信息
{
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
    int choice = ISBNOrNameOrPublisher(); //ISBN为1  Name为2 Publisher为3
    Link *p = head;
    if(choice == 1)
    {
        p = LinkfindByISBN(head);
        if(!p) 
		{
			cout << right << setw(LENGHT) << " " << "未找到该图书" << endl;
			return false;
		}
        BookPrint(p->next);
    }
    else if(choice == 2)
    {
		string name;
		cout << right << setw(LENGHT) << " " << "请输入部分书名：";
		cin >> name;
		int i = 1;
        while((p = i ? LinkfindByName(p, name) : LinkfindByName(p->next, name)))
        {
			i = 0;
            BookPrint(p->next);
        }
		if(i)
		{
			cout << right << setw(LENGHT) << " " << "未找到该图书" << endl;
			return false;
		}
    }
    else if(choice == 3)
    {
		string publisher;
		cout << right << setw(LENGHT) << " " << "请输入出版社名称：";
		cin >> publisher;
		int i = 1;
        while((p = i ? LinkfindByPublisher(p, publisher) : LinkfindByPublisher(p->next, publisher)))
        {
			i = 0;
            BookPrint(p->next);
        }
		if(i)
		{
			cout << right << setw(LENGHT) << " " << "未找到该图书" << endl;
			return false;
		}
    }
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	cout << endl;
    return true;
}

void Tearvser(Link *head)
{
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	if(head == NULL) return;
	Link *p = head->next;
	while(p) 
	{
		BookPrint(p);
		p = p->next;
	}
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	cout << endl;
}

bool IsInIt(Statistics *head, string &ch)//查找1、作者或2、出版社是否存在 存在就++
{
	Statistics *p = head->next;
	while(p)
	{
		if(p->sort == ch)
		{
			p->count++;
			return true;
		}
		p = p->next;
	}
	return false;
}

void StatisticsAdd(Statistics *head, int flag)//输出具体信息
{
	Statistics *p = head->next;
	if(flag) cout << right << setw(LENGHT) << " " << "作者" << ":" << "数量" << endl;
	else cout << right << setw(LENGHT) << " " << "出版社" << ":" << "数量" << endl;
	while(p)
	{
		cout << right << setw(LENGHT) << " " << p->sort << ":" << p->count << endl;
		p = p->next;
	}
	cout << endl;
	
}

void StatisticsIt(Link *head)//统计作者或出版社 
{
	Link *p = head->next;
	Statistics *pWriter = new Statistics;
	Statistics *pPublisher = new Statistics;
	Statistics *temp = new Statistics;
	pWriter->next = NULL;
	pPublisher->next = NULL;
	while(p)
	{
		if(!IsInIt(pWriter, p->writer))
		{
			temp = new Statistics;
			temp->sort = p->writer;
			temp->count = 1;
			temp->next = pWriter->next;
			pWriter->next = temp;
		}
		if(!IsInIt(pPublisher, p->publisher))
		{
			temp = new Statistics;
			temp->sort = p->publisher;
			temp->count = 1;
			temp->next = pPublisher->next;
			pPublisher->next = temp;
		}
		p = p->next;
	}
	char cha = 0;
	cout << right << setw(LENGHT) << " " << "作者：" << getLenght(pWriter) << endl;
	cout << right << setw(LENGHT) << " " << "获取作者详细统计信息 (y/n)" << endl;
	cout << right << setw(LENGHT) << " ";
	cin >> cha;
	if(cha == 'y') StatisticsAdd(pWriter, 1);
	cout << endl;
	cout << right << setw(LENGHT) << " " << "出版社：" << getLenght(pPublisher) << endl;
	cout << right << setw(LENGHT) << " " << "获取出版社详细统计信息 (y/n)" << endl;
	cout << right << setw(LENGHT) << " ";
	cin >> cha;
	if(cha == 'y') StatisticsAdd(pPublisher, 0);
	
}

int getLenght(Statistics *head)//获取链表长度
{
	int i = 0;
	Statistics *p = head->next;
	while(p)
	{
		p = p->next;
		i++;
	}
	return i;
}

bool Read(Link *head)//从文件读入内存
{
	ifstream in("save.in", ios::in);
	if(!in) return false;
	Link *q = head;
	if(!(in >> head->ISBN)) return false;
	DecryptedRoot(head);
	string ISBN, bookname, writer, publisher, date;
	int price;
	while(in >> ISBN >> bookname >> writer >> publisher >> date >> price)
	{
		Link *p = new Link;
		p->ISBN = ISBN;
		p->bookname = bookname;
		p->writer = writer;
		p->publisher = publisher;
		p->date = date;
		p->price = price;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	in.close();
	return true;
}

bool Write(Link *head)//从内存写入文件
{
	if(!head) return false;
	Link *p = head->next, *t;
	ofstream out("save.in", ios::out);
	EncryptedRoot(head);
	out << head->ISBN << endl;
	while(p)
	{
		out << p->ISBN << endl << p->bookname << endl << p->writer << endl << p->publisher << endl << p->date << endl << p->price << endl;
		t = p;
		p = p->next;
		delete t;
		t = NULL;
 	}
	delete head;
	head = NULL;
	out.close();
	return true;
}

bool Save(Link *head)//保存
{
	if(!Write(head)) 
	{
		cout << right << setw(LENGHT) << " " << "保存失败！" << endl;
		return false;
	}
	cout << right << setw(LENGHT) << " " << "保存成功" << endl;
	head = new Link;
	Read(head);
	return true;
}
bool menu(Link *head) //菜单
{
    char choice;
	string check;
	Link *p = NULL;

	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	cout << right << setw(LENGHT) << " " << "管理员登录 (y/n)" << endl;
	cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
	cout << right << setw(LENGHT) << " ";
	cin >> check;
	if(check == "y" && IsRoot(head))
	{
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		cout << right << setw(LENGHT) << " " << "欢迎，管理员" << endl;
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		while(1)
		{
			cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
			cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
			cout << right << setw(LENGHT) << " " << "***          请选择操作（输入序号）         ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          1、添加图书                    ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          2、删除图书                    ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          3、修改图书信息                ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          4、查找图书                    ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          5、遍历图书                    ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          6、统计                        ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          7、修改管理员密码              ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          8、保存                        ***" << endl;
			cout << right << setw(LENGHT) << " " << "***          9、退出                        ***" << endl;
			cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
			cout << right << setw(LENGHT) << " " << "***********************************************" << endl;

			

			cout << right << setw(LENGHT) << " ";
			cin >> check;
			if(check.length() != 1)
			{
				cout << right << setw(LENGHT) << " " << "请输入有效选项" << endl;
				continue;
			}
			choice = check[0];
			switch(choice){
				case '1': 
						  cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
						  p = NULL; p = new Link; LinkInput(p); 
						  if(!LinkInsert(head, p))
						  {
							cout << right << setw(LENGHT) << " " << "添加失败" << endl;
							free(p);
							p = NULL;
						  }
						  else
							cout << right << setw(LENGHT) << " " << "添加成功" << endl;
						  cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
						  cout << endl;
						  break;
				case '2': 
						  cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
						  if(!Linkdelete(head))
							cout << right << setw(LENGHT) << " " << "删除失败" << endl;
						  else
						  cout << right << setw(LENGHT) << " " << "删除成功" << endl;
						  cout << right << setw(LENGHT) << " " << "***********************************************" << endl << endl;
						  break;
				case '3': LinkChange(head); break;
				case '4': BookShow(head); break;
				case '5': Tearvser(head); break;
				case '6': StatisticsIt(head); break;
				case '7': ResetRoot(head); break;
				case '8': Save(head); break;
				case '9': return true;
				default: cout << right << setw(LENGHT) << " " << "请输入有效选项" << endl;
			}
		}
	}
    cout << right << setw(LENGHT) << " " << "***********************************************" << endl << endl;
	cout << right << setw(LENGHT) << " " << "欢迎，游客" << endl;
    cout << right << setw(LENGHT) << " " << "***********************************************" << endl << endl;
	while(1)
	{
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		cout << right << setw(LENGHT) << " " << "***          请选择操作（输入序号）         ***" << endl;
		cout << right << setw(LENGHT) << " " << "***          1、查找图书                    ***" << endl;
		cout << right << setw(LENGHT) << " " << "***          2、遍历图书                    ***" << endl;
		cout << right << setw(LENGHT) << " " << "***          3、统计                        ***" << endl;
		cout << right << setw(LENGHT) << " " << "***          4、退出                        ***" << endl;
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;
		cout << right << setw(LENGHT) << " " << "***********************************************" << endl;

		

		cout << right << setw(LENGHT) << " ";
		cin >> check;
		if(check.length() != 1)
		{
			cout << right << setw(LENGHT) << " " << "请输入有效选项" << endl;
			continue;
		}
		choice = check[0];
		switch(choice){
			case '1': BookShow(head); break;
			case '2': Tearvser(head); break;
			case '3': StatisticsIt(head); break;
			case '4': return true;
			default: cout << right << setw(LENGHT) << " " << "请输入有效选项" << endl;
		}
	}
}
