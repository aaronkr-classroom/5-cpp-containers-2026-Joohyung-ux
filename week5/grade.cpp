#include <vector>
#include <stdexcept>
#include "Students_info.h"
#include "grade.h"
#include "median.h"
/*//main.cpp

//중간고사, 기말고사, 그리고 과제 점수 몇개를 받고

//마지막 평균 결과 점수를 계산하기.

#include <algorithm> // sort()
#include <ios>
#include <iostream>
#include <iomanip> //setprecision()
#include <vector>
#include <stdexcept> //istream& 위해
#include <string>
#include "Students_info.h"
#include "grade.h"

using namespace std;

typedef vector<double>::size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;


//함수원형 정의문
istream& read_hw(istream&, vector<double>&);
double median(vector<double>);


int main(void) {
	//새로운 구조 자료형 선언
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//학생의 이름을 묻고 읽음
	cout << "For every student, enter" << endl <<
		"Name Midterm Final Hw1 Hw2. . ." << endl;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// 학생 정보를 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	// 모든 학생의 결과를 출력
	for (si_sz i = 0;
		i != students.size(); ++i) {
		//이름과 오른쪽 공백을 포함하여 maxlen + 1개의 문자를 출력
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		//최종 점수를 계산하여 출력
		try {
			double final_grade = grade(students[i]); // NEW 계산하는 함수 grade()
			streamsize prec = cout.precision();
			cout << setprecision(3) <<
				final_grade << setprecision(prec) << endl;
		}

		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}



	return 0;

}

*/

double grade(double mid, double fin, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("No homework!");
	}

	// return (mid * 0.2 + fin * 0.4 + (hw1 + hw2 ...) / hw.size())

	//NEW grade() 함수 

	return grade(mid, fin, median(hw));

}

//계산하는 grade()함수
double grade(double midterm, double final, double homework) {
	return midterm * 0.2 + final * 0.4 + homework * 0.4;

}

//students_info 계산
double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	//vector<Student_info>::size_type i = 0;
	list<Student_info>::iterator iter = students.begin();

	//불변성: students 벡터의 [0,i)범위에 있는
	//요소들은 과목을 통과한 학생들의 정보
	//while (i != students.size()) {
	while (iter != students.end()) {
		//if (fgrade(students[i])) {
		if (fgrade(*iter)) {
			//fail.push_back(students[i]);
			fail.push_back(*iter);
			//students.erase(students.begin() + i); //i번째 제거
			iter = students.erase(iter);
		}


		else {
			//++i;
			++iter;
		}
	}
	return fail;
}