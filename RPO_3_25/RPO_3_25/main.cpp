#include <iostream>
#include <Windows.h>

std::string korzinaName[64]{};
int  korzinaCol[64]{}, korzinaPrice[64]{};
bool skid = false;
double skidka13(double sum) {
	if (sum > 670) {
		skid = true;
		sum -= sum / 100 * 13;
			return sum;
	}
	return sum;
}

int luk() {
	int col_l = 0;
	for (size_t i = 0; i < 64; i++)
	{
		if (korzinaName[i] == "луковый") {
			col_l += korzinaCol[i];
		}
	}
	return col_l / 4;
}

double skidka_petr(){
	int col = 0;
	double sum_skid = 0;
	for (size_t i = 0; i  < 64; i ++)
	{
		if (korzinaName[i] == "петрушевый") {
			col += korzinaCol[i];
		}
	}
	if (col >= 3) {
		for (size_t i = 0; i < 64; i++)
		{
			if (korzinaName[i] == "петрушевый") {;
				sum_skid += (korzinaPrice[i] * korzinaCol[i]) / 100 * 5;
			}
		}
	}
	return sum_skid;
}
void add(std::string name, int price, int col) {
	for (int i = 0; i < 64; i++) {
		if (korzinaName[i] == "") {
			korzinaName[i] = name;
			korzinaPrice[i] = price;
			korzinaCol[i] = col;
			return;
		}
	}
	return;
}
bool bayra() {
	for (int i = 0; i < 64; i++) {
		if (korzinaName[i] == "боярышник") {
			korzinaName[i] = "";
			korzinaCol[i] = 0;
			korzinaPrice[i] = 0;
			return true; 
		}
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Qt
	srand(time(NULL));
	int tovar , col, user , korzina;


	std::string fruct[4] = { "яблочный", "апельсиновый", "абрикосовый", "грушевый" }, ovosh[3] = { "томатный","луковый","огуречный" }, tea[2] = { "чесночный", "петрушевый" }, nastoi[1]{"боярышник"};
	int priceFruct[4] = { 30 , 40 , 60 , 50 }, priceOvosh[3] = { 45 , 70 , 25 }, priceTea[2] = { 200 , 100 }, priceNas[1]{1000};


	while (true)
	{
		std::cout << "Добро пожаловать в магазин отравы!!!\n" << "1.Посмотреть каталог\n2.Выйти\n3.Посмотреть корзину\n";
		std::cin >> user;


		if (user == 2) {
			int sum = 0;
			std::cout << "Вы вышли из магазина , запустите программу заново...\n";
			for (int i = 0; i < 64; i++) {
				
				sum += korzinaPrice[i];

			}
			sum -= skidka_petr();
			if (skid = true) {
				std::cout << skidka13(sum) << " рублей составили ваши покупки с учетом скидок, а также " << luk() << " бесплатных литров лука\n";
			}
			
			break;
		}
		else if (user == 1) {

			std::cout << "Вот весь наш каталог:\n";
			std::cout << "Фруктовые соки:\n";
			for (int i = 0; i < 4; i++) {
				std::cout << fruct[i] << "\n";
			}
			std::cout << "Овощные соки: \n";
			for (int i = 0; i < 3; i++) {
				std::cout << ovosh[i] << "\n";
			}
			std::cout << "Чаи: \n";
			for (int i = 0; i < 2; i++) {
				std::cout << tea[i] << "\n";
			}
			std::cout << "Настойки: \n";
			for (int i = 0; i < 1; i++) {
				std::cout << nastoi[i] << "\n";
			}
			std::cout << "Введите товар который вы хотите купить в таком формате (F1 , O2 , T1) выберите категорию(F/O/T/N) затем товар из этой категории (2/3/1):\n";
			char category;
			int vibor;
			std::cin >> category >> vibor;
			std::cout << "Введите количество:\n";
			std::cin >> col;
			int index = vibor - 1;

			if (category == 'F') {
				if (!bayra()) {
					tovar = priceFruct[index] * col;
					std::cout << "Вы успешно добавили в корзину | " << fruct[index] << "|" << col << "литров\n";
					add(fruct[index], priceFruct[index], col);

					continue;
				}
			}
			else if (category == 'O')
			{
				std::cout << "Вы успешно добавили в корзину | " << ovosh[index] << "|" << col << "литров\n";
				add(ovosh[index], priceOvosh[index], col);
				continue;
			}
			else if (category == 'T')
			{
				std::cout << "Вы успешно добавили в корзину | " << tea[index] << "|" << col << "литров\n";
				add(tea[index], priceTea[index], col);
				continue;

			}
			else if (category == 'N') {
				if (bayra()) {
					add(nastoi[index], priceNas[index], col);
					std::cout << "Вы успешно добавили в корзину | " << nastoi[index] << "|" << col << "литров\n";
					continue;
				}
				else {
					std::cout << "У ВАС УЖЕ ЕСТЬ СОК В КОРЗИНЕ ВЫ НЕ МОЖЕТЕ КУПИТЬ НАСТОЙКУ!!!!\n";
				}
			}
			else {
				std::cout << "Вы ввели неизвестную категорию вы перенесены на главное меню!!!";
				continue;
			}
			
		}
		else if (user == 3) {
			int sum = 0;
			std::cout << "Ваша корзина:\n";
			for (int i = 0; i < 64; i++) {
				if (korzinaName[i] != "") {
					std::cout << korzinaName[i] << "\t" << korzinaCol[i] << "\t" << korzinaPrice[i] << "\n";
					sum += korzinaPrice[i];
			
				}
			}
			std::cout << "итоговая сумма вашей корзины составила:" << sum << "\nУчитывая скидку выходит : " << skidka13(sum - (skidka_petr())) << ", а также " << luk() << " бесплатных литров лука\t\n";

		}
	}
	return 0;
}

/*
	std::cout << "Hello world " << 100 + 10 << std::endl;
	std::cout << "info\n" << "FGHJGHJGJ\n\n\n\n\n";
	std::cout << "Денис\n\t" << 16 << "\nнет\n\t\t" << "есть мясо\n" << one << "руб\n\t" << "не знаю";
	// тип_данных имя_переменной
	int one = 0;
* 
* 
* 
*	чтобы переменную нельзя было изменить - const
	типы данных:
	bool - true/false  0 - false 
	char - 'r' один символ '+' 43  ot - 128 do 127
	unsigned char - 0 - 255

	short - 123 ot -32768 do 32767
	unsigned short - 123 0 -- 65535

	int - 123456 -  -21474836448--21474836447
	unsigned int 123456 0 - 4294967295

	float 123.542 +-3.4e-38...3.4e+38

	double 123123.123123 +- 1.7e-308...1.7e-308
	long double no comment 3.4-4932

	long long int ..............

	auto ??? 



	операторы: 


	математические: + - / * % () ++ -- += -= *= /= = 
	сравнительные: < > <= >= == != <=>
	логические: && - и || - или ! - не 

	ТАБУ: goto   and or not    int номерОдин;


КАЛЬКУЛЯТОР 

int Plus(double ch1, double ch2)
{
	return ch1 + ch2;
}
int Minus(double ch1, double ch2)
{
	return ch1 - ch2;
}
int Mnoj(double ch1, double ch2)
{
	return ch1 * ch2;
}
int Del(double ch1, double ch2)
{
	return ch1 / ch2;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Qt
	srand(time(NULL));

	double ch1, ch2;
	char znak;
	std::cout << "Введите первое число\n";
	std::cin >> ch1;
	std::cout << "Введите знак\n";
	std::cin >> znak;
	std::cout << "Введите второе число\n";
	std::cin >> ch2;

	if (znak == '+')
	{
		std::cout << Plus(ch1, ch2);
	}
	else if (znak == '-')
	{
		std::cout << Minus(ch1, ch2);
	}
	else if (znak == '*')
	{
		std::cout << Mnoj(ch1, ch2);
	}
	else if (znak == '/')
	{
		if (ch2 != 0)
		{
			std::cout << Del(ch1, ch2);
		}
		else {
			std::cout << "Нельзя делить на ноль !!!";
		}
	}
	else{
		std::cout << "Вы ввели несуществующий знак...\n";
	}


	return 0;
}


double one = 0;
	double two = 0;
	char sym;
	while (true)
	{
		std::cout << "Привет , это калькулятор , вначале ты должен выбрать числа с которыми хочешь выполнить действие , а потом знак для него , удачи:)\n";
		std::cout << "Введи первое число: ";
		std::cin >> one;
		std::cout << "\nВведи второе число :";
		std::cin >> two;
		std::cout << "\nВведи действие(+ , - , * , /):" ;
		std::cin >> sym;




		if (sym == '+')
		{
			std::cout << "твой ответ: " << one + two;
			break;
		}
		else if (sym == '-')
		{
			std::cout << "твой ответ: " << one - two;
			break;
		}
		else if (sym == '*')
		{
			std::cout << "твой ответ: " << one * two;
			break;
		}
		else if (sym == '/')
		{
			if (two != 0)
			{
				std::cout << "твой ответ: " << one / two;
			}
			else
			{
				std::cout << "НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ !!!!!!";
			}

			break;
		}
		else if (sym == '/' || or && two != 0 && )
		{
			std::cerr <<
			std::clog <<
			std::cout << "твой ответ: " << one / two;

			break;
		}
	
		else
		{
			std::cout << "Такой знак наш калькулятор не поддерживает...попробуй еще раз\n";

			}
	}
	ДИСКРИМИНАНТ 
	double a = 0, b = 0, c = 0 , d = 0 , x1 = 0, x2 = 0;

	std::cout << "Решение полного квадратного уравнения\n\n";
	std::cout << "ax^2 + bx + c = 0\n\n";
	std::cout << "Введите A: ";
	std::cin >> a;
	std::cout << "Введите B: ";
	std::cin >> b;
	std::cout << "Введите C: ";
	std::cin >> c;

	std::cout << a << "x^2" << b << "x + " << c << "= 0\n\n";

	d = std::pow(b, 2) - 4 * a * c;

	std::cout << "Дискриминант: " << d << "\n\n";

	if (d < 0)
	{
		std::cout << "корней нет !\n";
	}
	else if (d == 0)
	{
		x1 = -b / (2 * a);
		std::cout << "один корень: " << x1 << "\n";
	}
	else if (d > 0)
	{
		x1 = (-b + std::sqrt(d)) / (2 * a);
		x2 = (-b - std::sqrt(d))/ (2 * a);
		std::cout << "x1:" << x1 << "\n";
		std::cout << "x2:" << x2 << "\n";

	ЦИКЛЫ
	/*
	тип_возврата Имя_функции(аргументы_функции , ...)
	{
		тело_функции

void PrintHello()
{
	std::cout << "Hello\n";
}

void PrintNumint a , double b)
{(
	a += b;
	std::cout <<  a + b << "\n";
}

int Sum(int a, int b)
{
	return a + b;
}

	}

*/
/*template <typename T1>
T1 Substruct(T1 one, T1 two)
{
	return one - two;
}

int Fak(int num) {

	if (num < 0)
	{
		return 0;
	}
	if (num == 0)
	{
		return 1;
	}
	return num * Fak(num - 1);
}
int mnoj(int num, int num2)
{
	if (num2 == 0 || num == 0)
	{
		return 0;
	}
	if (num2 < 0)
	{
		return mnoj(num, -num2);
	}
	return num + mnoj(num, num2 - 1);
}


	int schet = 0;
	int prov = 0;
	while (true)
	{
		std::cout << "Ввведите любое число: ";
		std::cin >> prov;
		schet += prov;
		if (prov == 0)
		{
			std::cout << "Все числа в сумме: " << schet;
			break;
		}
	}

		int a = 0;
	do
	{
		std::cout << "Выберите пункт меню \n 1) Ларионов \n 2) Александр \n 3) Дмитриевич : ";
		std::cin >> a;

	} while (a < 1 || a > 3);

	if (a == 3)
	{
		std::cout << " Дмитриевич";
	}
	else if (a == 2)
	{
		std::cout << " Александр\n";
	}
	else
	{
		std::cout << " Ларионов\n";
	}



		const int ogr = 10;
	int massiv[10]{};
	double summplus = 0, summminus = 0 , arif = 0;


	for (size_t i = 0; i < ogr; i++)
	{
		massiv[i] = rand() % 21 - 10;
		std::cout << massiv[i] << "\n\n";
	}
	for (size_t i = 0; i << ogr; i++)
	{
		std::cout << massiv[i];
	}

	for (size_t i = 0; i < ogr; i++)
	{
		if (massiv[i] > 0)
		{
			summplus += massiv[i];
		}
		else if (massiv[i] < 0)
		{
			summminus += massiv[i];
		}
	}

	arif = (summplus + summminus) / ogr;
	std::cout << "сумма положительных чисел: " << summplus << "\n\n";
	std::cout << "сумма отрицательных чисел: " << summminus << "\n\n";
	std::cout << "среднее арифметическое:  " << arif ;






	//std::foreach
	//const int row = 3, col = 4;
	//int arr[row][col]{ {1,2,3,4} , {3,2,1,0}, {5,,4,1} };

	const int row = 3, col = 4;
	int arr[row][col]{};
	for (size_t i = 0; i < row; i++)
	{
		for(size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 11;
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
	void FillArray(int massiv[] , int size) {
	for (int i = 0; i < size; i++) {
		massiv[i] = rand() % 100 + 1;
	}
}

void FillArray(double massiv[], int size) {
	for (int i = 0; i < size; i++) {
		massiv[i] = (double)(rand() % 100 + 1);
	}
}
void FillArray(char massiv[], int size) {
	for (int i = 0; i < size; i++) {
		massiv[i] = (char)(rand() % 26 + 97);
	}
}


void ShowArray(int massiv[]) {
	for (int i = 0; i < 4; i++) {
		std::cout << " " << massiv[i];
	}
}
void ShowArray(double massiv[]) {
	for (int i = 0; i < 4; i++) {
		std::cout << " " << massiv[i];
	}
}
void ShowArray(char massiv[]) {
	for (int i = 0; i < 4; i++) {
		std::cout << " " << massiv[i];
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Qt
	srand(time(NULL));
	const int razmer = 4;
	int SpisokInt[razmer];
	double SpisokDouble[razmer];
	char SpisokChar[razmer];
	int user, size;
	std::cout << "Введите какой список хотите заполнить и вывести (1.SpisokInt , 2.SpisokDouble , 3.SpisokChar) ";
	std::cin >> user;
	if (user == 1) {
		FillArray(SpisokInt, razmer);
		ShowArray(SpisokInt);
	}
	else if (user == 2) {
		FillArray(SpisokDouble, razmer);
		ShowArray(SpisokDouble);
	}
	else if (user == 3) {
		FillArray(SpisokChar, razmer);
		ShowArray(SpisokChar);
	}
	else {
		std::cout << "Вы ввели неизвестное значение!!!";
	}

	return 0;
}

*/