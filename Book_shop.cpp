#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//***** Function Prototype ******//
double cm_to_inch(double value);
double pound_to_gram(double value);
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
    double total_price = price;
    double cheapest_price = price;

    //***** Looping for each book price *****//
    for(int i = 1; i < books; i++){
        cout << "Book " << i+1 << ":\n";
        price = one_book_price();
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
            total_price -= discount;
        }
    }

    cout << setprecision(5) << "Total price = " << total_price << endl;

    return 0;
}

//***** Unit Convertion *****//
double cm_to_inch(double value){
    return value / 2.54;
}

//***** Unit Convertion *****//
double pound_to_gram(double value){
    return value * 453.592;
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

//***** Function to calculate member discount *****//
double member_discount(double cheapest_price){
    return cheapest_price * 0.2;
}
