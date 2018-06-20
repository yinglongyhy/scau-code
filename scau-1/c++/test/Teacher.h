#include <iostream>
#include <string>
using namespace std;
class Teacher
{
	public:
		Teacher(string name, int score);
		void setName(string name);
		string getName();
		void setScore(int score);
		int getScore();

	private:
		string m_strName;
		int m_iScore;
};
