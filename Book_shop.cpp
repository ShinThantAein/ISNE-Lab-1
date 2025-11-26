#include <iostream>
#include <cmath>
using namespace std;

//***** Function Prototype ******//
double inch_to_cm(double value);
double gram_to_pound(double value);
double surface_area(double w, double h);
double discount_for_instockday(int instock_day);
double one_book_price();
double member_discount(double cheapest_price);

int main() {

    int books;

    cout << "Enter number of books : ";
    cin >> books;

    cout << "Book 1 : " << endl;
    double price = one_book_price();
    cout << "Book 1 Price : " << price << endl;
    double total_price = price;
    double cheapest_price = price;

    //***** Looping for each book price *****//
    for(int i = 1; i < books; i++){
        cout << "Book " << i+1 << ":\n";
        price = one_book_price();
        cout << "Book " << i+1 << " Price : " << price << endl;
        total_price += price;

        if(price < cheapest_price){
        cheapest_price = price;
        }
    }

    //***** Member Discount Check *****//
    int answer, discount_for_member;
    cout << "Are you a member? (1 for yes / 0 for no): ";
    cin >> answer;

    if(answer == 1){                     
        if(books >= 3){                    
            double discount = member_discount(cheapest_price);
            cout << "Discout for cheapest book : " << discount << endl;
            total_price -= discount;
        }
    }

    cout << "Total price = " << total_price << endl;

    return 0;
}

//***** Unit Convertion *****//
double inch_to_cm(double value){
    return value * 2.54;
}

//***** Unit Convertion *****//
double gram_to_pound(double value){
    return value * 0.00220462;
}

//***** Function to calculate surface area *****//
double surface_area(double w, double h){
    return w * h;
}

//***** Function to calculate discount for instock days *****//
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

//***** Function to calculate one book price *****//
double one_book_price(){

    double w, h, weight;
    int pages, instockday;

    cout << "Enter book width (inch): ";
    cin >> w;
    w = inch_to_cm(w);

    cout << "Enter book height (inch): ";
    cin >> h;
    h = inch_to_cm(h);

    cout << "Enter book weight (gram): ";
    cin >> weight;
    weight = gram_to_pound(weight);

    cout << "Enter number of pages: ";
    cin >> pages;

    cout << "Enter number of instock days: ";
    cin >> instockday;

    double SA = surface_area(w, h);

    double price = SA * weight * 10 + sqrt(pages) - discount_for_instockday(instockday);

    return price;
}

//***** Function to calculate member discount *****//
double member_discount(double cheapest_price){
    return cheapest_price * 0.2;
}
