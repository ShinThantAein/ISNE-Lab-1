#include <iostream>
#include <cmath>
using namespace std;

double cm_to_inch(double value);
double pound_to_gram(double value);
double surface_area(double w, double h);
double discount_for_instockday(int instock_day);
double one_book_price();

int main() {

    int books;
    double total_price = 0;

    cout << "Enter number of books : ";
    cin >> books;

    for(int i = 0; i < books; i++){
        double price = one_book_price();
        total_price += price;
    }

    cout << "Total price = " << total_price << endl;

    return 0;
}

double cm_to_inch(double value){
    return value / 2.54;
}

double pound_to_gram(double value){
    return value * 453.592;
}

double surface_area(double w, double h){
    return w * h;
}

double discount_for_instockday(int instock_day){
    double discount = 0;

    if(instock_day > 20){
        discount = (10 * 2) + ((instock_day - 20) * 5);
    }
    else if(instock_day > 10){
        discount = (instock_day - 10) * 2;
    }
    else {
        discount = 0;
    }

    return discount;
}

double one_book_price(){

    double w, h, weight;
    int pages, instockday;

    cout << "Enter book width (cm): ";
    cin >> w;
    w = cm_to_inch(w);

    cout << "Enter book height (cm): ";
    cin >> h;
    h = cm_to_inch(h);

    cout << "Enter book weight (pounds): ";
    cin >> weight;
    weight = pound_to_gram(weight);

    cout << "Enter number of pages: ";
    cin >> pages;

    cout << "Enter number of instock days: ";
    cin >> instockday;

    double SA = surface_area(w, h);

    double price = SA * weight * 10 + sqrt(pages) - discount_for_instockday(instockday);

    return price;
}