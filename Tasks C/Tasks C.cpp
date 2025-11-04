#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace
{
    void argregatorPersolalInfo(int age, double weight) {

        double height;
        wstring name{ L"Vladislav" }, description;

        wcout << "Name: " << name << "\n";
        wcout << "Age: " << age << " Weight: "
            << weight << endl;

        {
            wcout << "Enter height:" << endl;
            cin >> height;
            wcin >> description;
        }
    }

    void argregatorPersolalInfo()
    {
        argregatorPersolalInfo(27, 77.3);
    }
}

namespace problems
{
    // TO DO:
    /*
    * Дано трехзначное натуральное число N.
    * Нужно найти сумму цифр числа N
    */
    int problem1() {
        int N;
        std::cin >> N;
        return N % 10 + (N / 10) % 10 + N / 100;
    }

    int problem1AlexR() {
        int N;
        std::cin >> N;

        auto acc{ 0 };
        while (N) {
            //acc = acc + N % 10;
            acc += N % 10;
            N /= 10;
        }

        return acc;
    }

    int problem1Diamond() {
        std::string number_str;
        std::cin >> number_str;

        auto it = number_str.begin();

        auto acc{ 0 };
        //for (int index = 0; index < number_str.length(); index++)
        //    acc += number_str[index] - '0';

        for (auto symbol : number_str)
            acc += symbol - '0';
        return acc;
    }

    /*
    * Дано шестизначное натуральное число n,
    найти сумму его четных и нечетных элементов,
    и вывести их на экран подряд.
    Пример: 531277
    Вывод: 1312
    */
    int problem2() {
        string n;
        cin >> n;
        int k = 1;
        int k1{ 0 }, k2{ 0 };
        for (auto& i : n) {
            if (k % 2 == 0) {
                k2 += i - '0';
            }
            if (k % 2 != 0) {
                k1 += i - '0';
            }
            k += 1;
        }
        cout << k1 << k2 << endl;
        return 0;
    }
    /*
    * На вход подается наутральное число k
    * Затем подается n натуральных чисел
    * Нужно найти количесвто чисел, равных k
    */
    int problem3() {
        int n = 0, k = 0, m = 0, count = 0;
        cin >> k;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> m;
            count += (m == k);
        }
        cout << count << endl;
        return 0;
    }
    /*
    * На вход подается n натуральных чисел
    * Нужно найти среднее арфиметическое среди всех чисел кратных 3
    */
    double problem4() {
        int n;
        cin >> n;
        double sm = 0;
        double ln = 0;
        while (n--) {
            int number = 0;
            cin >> number;
            if (number % 3 == 0) {
                sm += number;
                ln += 1;
            }
        }
        if (ln > 0)
            return sm / ln;
        else
            return -1;
    }
    /*
    Задача 5
    Вводится натуральное число N,а затем N
    целых чисел последовательности.
    Найдите количество минимальных элементов в
    последовательности.
    */
    int problem5() {
        int N;
        int a;
        cin >> N;
        vector<int>h{};
        for (int i = 0; i < N; i++) {
            cin >> a;
            h.push_back(a);
        }
        int mn{ h[0] };
        for (int i : h)
        {
            mn = min(mn, i);
        }
        int count{ 0 };
        for (int i : h) {
            if (i == mn) count++;
        }
        return count;
    }
    /*
    * Задача 6
    Дано натуральное число A>1.
    Определите, каким по счету числом Фибоначчи оно является, то есть выведите такое число n что φ(n) = A.
    Если А не является числом Фибоначчи, выведите число -1.
    */
    int problem6() {
        int A{ 0 };
        int N{ 0 };
        vector<int>h{ 1,1 };
        cin >> A;
        if (A < 0) return -1;
        if (A == 1) return 1;
        for (int i{ 0 }; i < A + 10; i++) {
            if (i >= 2) {
                h.push_back(h[i - 2] + h[i - 1]);
                if (h[i] == A) return i + 1;
                if (h[i] > A) return -1;
            }
        }
    }
    /*
    * Задача 7
    Вводится два целых числа a и b. Найдите самое большее число на отрезке от a до b,
    кратное 7. Если такого числа нет выведите -1.
    */
    int problem7() {
        setlocale(LC_ALL, "Russian");
        int a, b;
        cout << "Введите a: " << endl;
        cin >> a;
        cout << "Введите b: " << endl;
        cin >> b;
        int mx{ 0 };
        for (a; a <= b; a++) {
            if (a % 7 == 0) {
                mx = max(mx, a);
            }
        }
        if (mx == 0) return -1;
        return mx;
    }
    /*
    *Задача 8
    В цепочках ДНК символы «А» и «Т» дополняют друг друга, как «С» и «G».
    Нужно написать программу, которая получает на вход последовательность ДНК
    и на выходе отображает комлементарную ей.
    */
    string problem8() {
        string s;
        cin >> s;
        for (int i{ 0 }; i < s.size(); i++) {
            if (s[i] == 'A') s[i] = 'T';
            else if (s[i] == 'T') s[i] = 'A';
            else if (s[i] == 'C') s[i] = 'G';
            else if (s[i] == 'G') s[i] = 'C';
        }
        return s;
    }
    /*
    * Задача 9
    По данному числу N распечатайте все целые значения степени двойки, не превосходящие N, в порядке возрастания.
    */
    void problem9() {
        int N{ 0 };
        cin >> N;
        int t{ 1 };
        while (t <= N) {
            cout << t << " ";
            t = t * 2;
        }
    }
    /*
    * Задача 10
    На ввод подаются N целых чисел, их нужно сохранить в массив или список. Затем вывести максимальный элемент.
    */
    int problem10() {
        int N, chislo;
        vector<int>h{};
        cin >> N;
        for (int i{ 0 }; i < N; i++) {
            cin >> chislo;
            h.push_back(chislo);
        }
        int mx{ 0 };
        for (int i : h) {
            mx = max(mx, i);
        }
        return mx;
    }
    /*
    *Задача 11
    Сначала на вход поступает длина последовательности N. Затем элементы последовательности – целые числа.
    Напишите программу, которая подсчитывает количество положительных чисел среди элементов последовательности.
    */
    int problem11() {
        int N = 0, count = 0, chislo = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> chislo;
            if (chislo > 0) count++;
        }
        return count;
    }
    /*
    *Задача 12
    Напишите программу, которая в последовательности чисел находит сумму двузначных чисел, кратных 8.
    Программа в первой строке получает на вход число n − количество чисел в последовательности,
    во второй строке − n чисел, входящих в данную последовательность.
    */
    int problem12() {
        int N = 0, sm = 0, x = 0;
        cin >> N;
        vector <int>h;
        while (N) {
            cin >> x;
            if (10 <= abs(x) && x <= 99 && x % 8 == 0) sm += x;
            N--;
        }
        return sm;
    }
    /*
    * Задача 13
    Последовательность состоит из натуральных чисел и завершается числом 0.
    Определите количество элементов этой последовательности, которые равны ее наибольшему элементу.
    */
    int problem13() {
        int x = 1, mx = 0, count = 0;
        while (x != 0) {
            cin >> x;
            if (x == mx) count += 1;
            if (x > mx) {
                count = 1;
                mx = x;
            }
        }
        return count;
    }
    /*
    * Задача 14
    Даны два числа. Определить цифры, входящие в запись как первого, так и второго числа.
    Программа должна вывести цифры, которые имеются в обоих числах, через пробел.
    Цифры выводятся в порядке их нахождения в первом числе.
    */
    int problem14() {
        string C1, C2;
        cin >> C1;
        cin >> C2;
        for (char i : C1) {
            for (char j : C2) {
                if (i == j) {
                    cout << i << " ";
                    break;
                }

            }
        }
        return 1;
    }
}


int main() {
    //argregatorPersolalInfo();
    //cout << problems::problem14();
    problems::problem14();
    system("pause");
}