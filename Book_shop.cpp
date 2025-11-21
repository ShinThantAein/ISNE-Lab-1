#include<iostream>
#include<cmath>
using namespace std;
double cm_to_inch(int);
double pound_to_gram(int);
double surface_area(int, int);
double discount_for_instockday(int);
double one_book_price();

int main(){

    int books;
    double total_price =0;
    double price, cheapest_price;

    cout << "Enter number of books : ";
    cin >> books;

    for(int i=0; i<books; i++){
        price = one_book_price();
        total_price += price;
    }



    return 0;
}

// //******* Unit_Convertion ********//

// double cm_to_inch(int value){
//     return value/ 2.54;
// }

// double pound_to_gram(int value){
//     return value * 453.592;
// }

// //******* Surface_Area_Calculatio *******//

// double surface_area(int w, int h){
//     return w * h;
// }

// //******** Calculating_Discount *******//

// double discount_for_instockday(int instock_day){
//     int discount = 0;

//     if(instock_day > 10 ){
//         discount = (instock_day - 10) * 2;
//     } else if(instock_day > 20) {
//         discount = (10*2) + ((instock_day - 20 ) * 5);
//     }else {
//         discount = 0;
//     }

// return discount;

// }

// //****** One Book Price *******//

// double one_book_price(){

//     int w,h, weight, pages, instockday;
//     cout << "Enter book width : ";
//     cin >> w;
//     w = cm_to_inch(w);

//     cout << "Enter book height : ";
//     cin >> h;
//     h = cm_to_inch(h);

//     cout << "Enter book weight : ";
//     cin >> weight;
//     weight = pound_to_gram(weight);

//     cout << "Enter number of pages : ";
//     cin >> pages;

//     cout << "Enter number of instock days :  ";
//     cin >> instockday;

//     double SA = surface_area(w,h);

//     double price = SA * weight * 10 + sqrt(pages) - discount_for_instockday(instockday);

//     return price;
// }