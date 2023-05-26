#include <iostream>
#include <fstream>
#include <string>

class UI {
private:
	int i4 = 0;
	int i5 = 0;
public:
	int q6 = 0;
	int q7 = 0;
	int q8 = 0;
	int Get_I4(int v) {
		if (v == 1) {
			return 1;
		}
		else return 0;
	}
	int Get_I5(int v) {
		if (v == 1) {
			return 1;
		}
		else return 0;
	}
	void Set_Q6(int v) {
		q6 = v;
	}
	void Set_Q7(int v) {
		q7 = v;
	}
	void Set_Q8(int v) {
		q8 = v;
	}
};

class Container {
private:
	int n1;
	int n2;
	int n3;
	int n4;
	int num;
public:
	int num1;
	int num2;
	int num3;
	int num4;

	void Set_N() {
		std::cout << "Введите количество компонентов в первом контейнере: ";
		std::cin >> num1;
		std::cout << std::endl;
		Set_N1(num1);

		std::cout << "Введите количество компонентов во втором контейнере: ";
		std::cin >> num2;
		std::cout << std::endl;
		Set_N2(num2);

		std::cout << "Введите вместимость в контейнере для брака: ";
		std::cin >> num3;
		std::cout << std::endl;
		Set_N3(num3);

		std::cout << "Введите вместимость в контейнере для компонентов с печать: ";
		std::cin >> num4;
		std::cout << std::endl;
		Set_N4(num4);
	}
	void Set_N1(int v) {
		n1 = v;
	};
	void Set_N2(int v) {
		n2 = v;
	}
	int Get_N1() {
		return n1;
	}
	int Get_N2() {
		return n2;
	}
	void Set_N3(int v) {
		n3 = v;
	};
	void Set_N4(int v) {
		n4 = v;
	}
	int Get_N3() {
		return n3;
	}
	int Get_N4() {
		return n4;
	}
	void Set_Num(int v) {
		num = v;
	}
	int Get_Num() {
		return num;
	}
};

class Sensor {
private:
	int i0 = 0;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
public:
	int Get_I0(int v) {
		if (v == 1) {
			return 1;
		}
		else return 0;
	}
	int Get_I1(int v) {
		if (v == 1) {
			return 1;
		}
		else return 0;
	}
	int Get_I2(int v) {
		if (v == 1) {
			return 1;
		}
		else return 0;
	}
	int Get_I3(int v) {
		if (v == 1) {
			return 1;
		}
		else return 0;
	}
};

class Drive {
public:
	int q0;
	int q1;
	int q2;
	int q3;
	void Set_Q0(int v) {
		q0 = v;
	}
	void Set_Q1(int v) {
		q1 = v;
	}
	void Set_Q2(int v) {
		q2 = v;
	}
	void Set_Q3(int v) {
		q3 = v;
	}
};

class Controller {
public:
	int RyanGosling;
	UI ui{};
	Drive drive{};
	Container container{};
	Sensor sensor{};
	void Step_1() {
		//шаг 1
		int v;
		std::cout << "Для старта нажмите 1 и Enter: " << std::endl;
		std::cin >> v;
		container.Set_N();
		if (ui.Get_I4(v) == 1) {
			drive.Set_Q0(1);
			record(0, 0, 0, 0, 1, 0);
			Step_2();
		}
		else std::cout << "ЭАЭАЭЭАЭАЭА" << std::endl;
	}
	void Step_2() {
		if (container.Get_N1() != 0) {
			container.Set_N1(container.Get_N1() - 1);
			container.Set_Num(1);
			Step_2b();
		}
		else if (container.Get_N2() != 0) {
			//std::cout << "Контейнер под номером 1 пуст." << std::endl;
			container.Set_N2(container.Get_N2() - 1);
			container.Set_Num(2);
			Step_2b();
		}
		else Step_2a();
	}
	void Step_2b() {
		if (container.Get_Num() == 1) {
			std::cout << "2б) Контейнер с заготовками не пустой. Открывается контейнер. В контейнере под номером один " <<  container.Get_N1() << " деталей." << std::endl;
			drive.Set_Q1(1);
			record(0, 1, 0, 0, 0, 0);
			Step_3();
		}
		else {
			std::cout << "2б) Контейнер с заготовками не пустой. Открывается контейнер. В контейнере под номером два " << container.Get_N2() << " деталей." << std::endl;
			drive.Set_Q1(1);
			record(0, 1, 0, 0, 0, 0);
			Step_3();
		}
	}
	void Step_2a() {
		std::cout << "2а)Контейнер с заготовками пустой. Вызов сигнала и остановка ленты." << std::endl;
		drive.Set_Q0(0);
		ui.Set_Q6(1);
		ui.Set_Q8(1);
		record(0, 0, 0, 0, 0, 0);
	}
	void Step_3() {
		drive.Set_Q1(0);
		std::cout << "3) Заготовка едет по ленте, но ещё не достигла датчика печати." << std::endl;
		int rand_num = rand() % 100 + 1;//создаем "шанс" брака детали
		if (rand_num >= 1 && rand_num <= 99) { //деталь не бракована 
			record(0, 0, 0, 0, 0, 0);
			Step_4();
		}
		else {
			if (container.Get_N3() != 0) {
				container.Set_N3(container.Get_N3() - 1);
				std::cout << "Деталь бракована, и попадает в контейнер под номером 3, в котором осталсоть места еще для " << container.Get_N3() << " деталей." << std::endl;
				record(0, 0, 0, 0, 0, 0);
				Step_2();
			}
			else Step_9();
		}
	}
	void Step_4() {
		drive.Set_Q3(sensor.Get_I3(1));
		std::cout << "4) Заготовка достигла датчика печати. Печать опускается." << std::endl;
		record(0, 0, 0, 1, 0, 0);
		Step_5();
	}
	void Step_5() {
		drive.Set_Q3(sensor.Get_I3(0));
		std::cout << "5) Деталь продолжает движение по ленте." << std::endl;
		record(0, 0, 0, 0, 0, 0);
		Step_6();
	}
	void Step_6() {
		std::cout << "6) Деталь достигла конца ленты. Открывается крышка контейнера для готовых заготовок." << std::endl;
		drive.Set_Q2(1);
		record(1, 0, 0, 0, 0, 0);
		Step_7();
	}
	void Step_7() {
		if (container.Get_N4() != 0) {
			Step_7b();
		}
		else Step_7a();
	}
	void Step_7b() {
		container.Set_N4(container.Get_N4() - 1);
		std::cout << "7)б Контейнер не заполнен. Продолжаем процесс в шаг 2. В контейнере номер 4 осталось еще " << container.Get_N4()  << " мест для заготовок" << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
		record(0, 0, 0, 0, 0, 0);
		Step_2();
	}
	void Step_7a() {
		std::cout << "7)а Контейнер стал заполнен.Останавливаем процесс." << std::endl;
		record(0, 0, 1, 0, 0, 0);
	}
	void Step_9() {
		std::cout << "9) При переходе в неизвестные состояния процесс должен быть остановлен." << std::endl;
		record(0, 0, 0, 0, 0, 0);
	}
	void appendToFile(const std::string& filename, const int* values, int count) {
		std::ofstream output(filename, std::ios::app); // открываем файл для добавления записей в конец
		if (output.is_open()) { // проверяем, успешно ли открыт файл
			for (int i = 0; i < 13; i++) { // обходим первые 13 элементов массива values
				if (i < count) {
					output << values[i] << ' '; // записываем значение и пробел после него
				}
				else {
					output << '0' << ' '; // дополняем строку нулями, если элементов в массиве меньше 13
				}
			}
			output << std::endl; // переходим на новую строку
			output.close(); // закрываем файл
		}
		if (count > 13) { // если в массиве values осталось больше 13 элементов
			appendToFile(filename, values + 13, count - 13); // вызываем рекурсивно эту же функцию, передавая оставшиеся элементы и уменьшая count на 13
		}
	}
	void record(int v01, int v11, int v21, int v31, int v41, int v51) {
		int v1 = sensor.Get_I0(v01);
		int v2 = sensor.Get_I1(v11);
		int v3 = sensor.Get_I2(v21);
		int v4 = sensor.Get_I3(v31);
		int v5 = ui.Get_I4(v41);
		int v6 = ui.Get_I5(v51);
		std::string filename = "data.txt";
		int values[] = {v1, v2, v3, v4, v5, v6, drive.q0, drive.q1, drive.q2, drive.q3, ui.q6, ui.q7, ui.q8 };
		int count = sizeof(values) / sizeof(values[0]);
		appendToFile(filename, values, count);
	}
};

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Controller controller{};
	controller.Step_1();

	std::cout << "Работа технологического процесса завершена." << std::endl << std::endl;
};
