#include <iostream>
#include <math.h>

using namespace std;


struct figure{
    int count_side;
    double lenght_side;
    double S;
    double P;
    double x;
    double y;
};

void input(figure *number);
void square(figure *number,int i);
void perimeter(figure *number,int i);
void output(figure *number);
void realloc(figure *p_number,int size_arr);
double get_max_S(figure *number,int size_arr);
double get_max_P(figure *number,int size_arr);
void clean();

int main()
{
    setlocale(LC_CTYPE,"");
    int size_arr,i;
    cout << "������� �������������� ����������?"<<endl;
    cin >> size_arr;

    figure *p_number = new figure[size_arr];

    int num=0;
    do{
        cout<<"1-���� ������ ��������������"<<endl;
        cout<<"2-����� ������ ��������������"<<endl;
        cout<<"3-����� MAX_S � MAX_P"<<endl;
        cout<<"0-��������� ������"<<endl;
        cout << "������� ��������: ";
        cin>>num;
        if(num==1){
            clean();
            input(p_number);
        }
        else if(num==2){
            clean();
            output(p_number);
        }else if(num==3){
            clean();
            int num_p;
            cout<<"1-����� ������������ ������� ��������������"<<endl;
            cout<<"2-����� ������������� ��������� ��������������"<<endl;
            cout<<"3-�������� � ����"<<endl;
            cin>>num_p;
            if(num_p==1){
                cout << "������������ �������:" << get_max_S(p_number,size_arr)<<endl;
            }else if(num_p==2){
                cout << "������������ ��������:" << get_max_P(p_number,size_arr)<<endl;
            }
            else{
                clean();
            }
        }
    }while(num!=0);
    cout << "������ ���������!"<<endl;


    return 0;
}
void input(figure *number){
    int i;
    cout << "������ ������ �������������� �������?"<<endl;
    cin >> i;
    i--;
    cout <<"������� ���������� ������\n";
    cin >>number[i].count_side;
    cout <<"������� ����� �������\n";
    cin >>number[i].lenght_side;
    cout <<"������� ���������� x\n";
    cin >>number[i].x;
    cout <<"������� ���������� y\n";
    cin >>number[i].y;

    square(number,i);
    perimeter(number,i);

    return;
}
void square(figure *number,int i){
    if(number[i].count_side==3){
        number[i].S=(number[i].lenght_side*number[i].lenght_side)*sqrt(3)/2;
    }
    else if(number[i].count_side==4){
        number[i].S=(number[i].lenght_side*number[i].lenght_side);
    }
    else{
       number[i].S=(number[i].count_side*(number[i].lenght_side*number[i].lenght_side))/(4*tan(M_PI/number[i].count_side));
    }
}
void output(figure *number){
    int i;
    cout << "������ ������ �������������� ��������?"<<endl;
    cin >> i;
    i--;
    cout << "�������������: " << i+1 << "\n";
    cout << "������� S: " << number[i].S << "\n";
    cout << "�������� P: " << number[i].P << "\n";
}
void perimeter(figure *number,int i){
    number[i].P=number[i].lenght_side*number[i].count_side;
}
void realloc(figure *p_number,int size_arr){
    figure *p_number_new = new figure[size_arr+1];
    cout <<"pn0: " << p_number[0].S;
    for(int i=0;i<size_arr-1;i++){
        p_number_new[i]=p_number[i];
    }
    delete[] p_number;
    p_number=p_number_new;
    delete[] p_number_new;
    p_number[1].S=12;
    cout <<"pn1: " << p_number[1].S;
}

double get_max_S(figure *number,int size_arr){
    int i=0;
    double max_S=number[i].S;
    for(int i=0;i<size_arr;i++){
        if(number[i].S>max_S){
            max_S=number[i].S;
        }
    }
    return max_S;
}
double get_max_P(figure *number,int size_arr){
    int i=0;
    double max_P=number[i].P;
    for(int i=0;i<size_arr;i++){
        if(number[i].P>max_P){
            max_P=number[i].P;
        }
    }
    return max_P;
}
void clean(){
    int i=0;
    while(i<100){
        cout<<endl;
        i++;
    }
    return;
}
