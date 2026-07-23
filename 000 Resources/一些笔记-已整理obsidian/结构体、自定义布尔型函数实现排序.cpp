#include<bits/stdc++.h>
using namespace std;

struct Student
{
	string name;
	int year;
	int month;
	int day;
	int order; // 记录输入顺序
};

//在排序的比较函数中，一定要使用 const & 来传递参数

// 按值传递 - 效率低
//bool compare(Student a, Student b) {
//    if (a.year != b.year) return a.year > b.year;
//    if (a.month != b.month) return a.month > b.month;
//    if (a.day != b.day) return a.day > b.day;
//    return a.order > b.order;
//}

// 按引用传递 - 效率高 
bool compare(const Student &a, const Student &b)
{
	// 年龄从小到大排 
	// 先比较年份
	if (a.year != b.year)
	{
		return a.year > b.year; // 年份大的生日更晚（年龄更小,应该排在前面）
	}
	// 年份相同比较月份
	if (a.month != b.month)
	{
		return a.month > b.month;
	}
	// 年月相同比较日期
	if (a.day != b.day)
	{
		return a.day > b.day;
	}
	// 生日完全相同，按输入顺序逆序（输入靠后的先输出）
	return a.order > b.order;
}

int main()
{
	int n;
	cin >> n;

	vector<Student> students(n);

	for (int i = 0; i < n; i++)
	{
		cin >> students[i].name >> students[i].year >> students[i].month >> students[i].day;
		students[i].order = i; // 记录输入顺序
	}

	// 排序
	sort(students.begin(), students.end(), compare);
 
	// 输出结果
	for (int i = 0; i < n; i++)
	{
		cout << students[i].name << endl;
	}

	return 0;
}
