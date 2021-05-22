#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <fstream>
using namespace std;
int people;
class order;
 class Menu
{
public:
  string name;
  string category;
  string veg_non;
  float price;
};
class order: public Menu
{
    public:
      float price=0;
      fstream Bill;
    public:
    void ordering(Menu dish1, Menu dish2, Menu dish3, Menu dish4, Menu dish5, Menu dish6, Menu dish7, Menu dish8, Menu dish9)
    {
      int Sr, i=0;
      float quantity,tot_price[60],price_arr[10],quant_arr[10];
      string dish_name[100];
    do{
    srnum:
    cout<<"Enter the SR.no of dish\n";
    cin>>Sr;
    if(cin.fail())
        {
            cin.clear();
            cin.ignore(200,'\n');
            cout << "\nPlease enter a number!\n\n";
            goto srnum;
        }
    if(Sr==0){
      exit(0);
    }
    else if(Sr==10){
    billing(tot_price, i,dish_name, quant_arr, price_arr);

    }
    else{
    quantity:
    cout<<"Enter the quantity\n";
    cin>>quantity;
    if(cin.fail())
        {
            cin.clear();
            cin.ignore(200,'\n');
            cout << "\nPlease enter a number!\n\n";
            goto quantity;
        }
    switch(Sr){
      case 1:
      price_arr[i]=dish1.price;
      quant_arr[i]=quantity;
      tot_price[i]=dish1.price*quantity;
      dish_name[i]=dish1.name;
      cout<<"Total price is: Rs."<<tot_price[i]<<endl;
      i++;
      break;
      case 2:
       price_arr[i]=dish2.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish2.price*quantity;
       dish_name[i]=dish2.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;

      break;
      case 3:
       price_arr[i]=dish3.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish3.price*quantity;
       dish_name[i]=dish3.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
      break;
      case 4:
       price_arr[i]=dish4.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish4.price*quantity;
       dish_name[i]=dish4.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
       break;
      case 5:
       price_arr[i]=dish5.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish5.price*quantity;
       dish_name[i]=dish5.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
      break;
      case 6:
       price_arr[i]=dish6.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish6.price*quantity;
       dish_name[i]=dish6.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
      break;
      case 7:
       price_arr[i]=dish7.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish7.price*quantity;
       dish_name[i]=dish7.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
      break;
      case 8:
       price_arr[i]=dish8.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish8.price*quantity;
       dish_name[i]=dish8.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
      break;
      case 9:
       price_arr[i]=dish9.price;
       quant_arr[i]=quantity;
       tot_price[i]=dish9.price*quantity;
       dish_name[i]=dish9.name;
       cout<<"Total price is: Rs."<<tot_price[i]<<endl;
       i++;
      break;
      default:
      cout<<"Enter valid input"<<endl;
    }
    }
    }while(Sr!=10);

        }
    void billing(float tot_price[],int i, string dish_name[], float quant_arr[], float price_arr[])
    {
      Bill.open("text.txt", ios::app);
      int  custom_id;
      srand(time(0));
      custom_id= rand() % 30 + 1000;
      cout<<"Sr. No."<<"\tDish Name"<<"\t\t Price"<<"\t\t Qty"<<"\t\tTot. Price\n";
      for(int j=0;j<i;j++){
        cout<<j+1<<"\t"<<dish_name[j]<<"\t\tRs."<<price_arr[j]<<"\t\t"<<quant_arr[j]<<"\t\tRs."<<tot_price[j]<<endl;
        price+=tot_price[j];
      }
      Bill<<"\nCustomer ID: "<<custom_id<<endl;
      Bill<<"Dish Name\t Price\t Qty\t Tot. Price"<<endl;
      for(int j=0;j<i;j++){
        Bill<<dish_name[j]<<"\t";
        Bill<<price_arr[j]<<"\t";
        Bill<<quant_arr[j]<<"\t";
        Bill<<tot_price[j]<<"\t"<<endl;
      }
      cout<<"\t\t\t\t\t\t   Total bill: Rs."<<price<<endl;
      discount(tot_price, price, i, dish_name,quant_arr, price_arr,people,custom_id);

    }

    void discount(float tot_price[],float price,int i, string dish_name[], float quant_arr[],float price_arr[],int people,int custom_id)
    {
      float disc,final_price;

        if(people>1&& people<=3)
        {
        disc=(0.1*price);
        final_price=price-disc;
        cout<<"\n\t\t\t\t   Total Bill after discount: Rs."<<final_price<<endl;
        GST(final_price);
        cout<<"Congrats! You saved Rs."<<disc<<endl;
        cout<<"Your Unique ID is: #"<<custom_id<<endl;
        cout<<"Thanks for coming! See u soon ;)"<<endl;
        }

        if(people<7&&people>3)
        {
        disc=(0.2*price);
        final_price=price-disc;
        cout<<"\t\t\t\t   Total Bill after discount: Rs."<<final_price<<endl;
        GST(final_price);
        cout<<"Congrats! You saved Rs."<<disc<<endl;
        cout<<"Your Unique ID is: #"<<custom_id<<endl;
        cout<<"Thanks for coming! See u soon ;) "<<endl;
        }

        if(people>=7)
        {
        disc=(0.3*price);
        final_price=price-disc;
        cout<<"\t\t\t\t   Total Bill after discount: Rs."<<final_price<<endl;
        GST(final_price);
        cout<<"Congrats! You saved Rs."<<disc<<endl;
        cout<<"Your Unique ID is: #"<<custom_id<<endl;
        cout<<"Thanks for coming!See u soon ;)"<<endl;

        }

        if(people==1)
        {final_price=price;
        cout<<"\t\t\t\t   Total Bill: Rs."<<final_price<<endl;
        GST(final_price);
        cout<<"Your Unique ID is: #"<<custom_id<<endl;
        cout<<"Thanks for coming!See u soon ;)"<<endl;
        }


    }
    void GST(float final_price)
    {
      float gst=0.05,gst_price;
      gst_price=(gst*final_price)+final_price;
      cout<<"\t\t\t\t   Bill with GST: Rs."<<gst_price<<endl;
      Bill<<"Bill with Gst:"<<gst_price<<endl;
    }
};

int main()
{
  Menu dish1;
  dish1.name="Chkn Tandoori";
  dish1.category="Main Course";
  dish1.veg_non="Non-Veg";
  dish1.price=1500;

  Menu dish2;
  dish2.name="Chkn Biryani";
  dish2.category="Main Course";
  dish2.veg_non="Non-Veg";
  dish2.price=750;

  Menu dish3;
  dish3.name="Veg Pulao";
  dish3.category="Main Course";
  dish3.veg_non="Veg";
  dish3.price=450;

  Menu dish4;
  dish4.name="Butter Paneer";
  dish4.category="Main Course";
  dish4.veg_non="Veg";
  dish4.price=650;

  Menu dish5;
  dish5.name="Chkn Kebab";
  dish5.category="Starters";
  dish5.veg_non="Non-Veg";
  dish5.price=930;

  Menu dish6;
  dish6.name="Stufd Mushroom";
  dish6.category="Starters";
  dish6.veg_non="Veg";
  dish6.price=530;

  Menu dish7;
  dish7.name="Mango Kulfi";
  dish7.category="Desserts";
  dish7.veg_non="Veg";
  dish7.price=250;

  Menu dish8;
  dish8.name="Gulab Jamun";
  dish8.category="Desserts";
  dish8.veg_non="Veg";
  dish8.price=200;

  Menu dish9;
  dish9.name="Mango Lassi";
  dish9.category="Beverages";
  dish9.veg_non="Veg";
  dish9.price=150;
  // MENU
  cout<<"\n\n#######\tDory's Cafe\t#######\n#######\t\t\t\t#######\n\n";
  people:
  cout<<"How many people you are there in total"<<endl;
  cin>>people;
  if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout << "\nPlease enter a number!\n\n";
        goto people;
    }

  cout<<"Sr. No. \tDish Name \t Dish Category \t\tVeg/Non-Veg \tDish Price\n"<<endl;

  cout<<"1.\t"<<dish1.name<<"\t\t"<<dish1.category<<"\t\t"<<dish1.veg_non<<"\t\t\tRs."<<dish1.price<<endl;

  cout<<"2.\t"<<dish2.name<<"\t\t"<<dish2.category<<"\t\t"<<dish2.veg_non<<"\t\t\tRs."<<dish2.price<<endl;

  cout<<"3.\t"<<dish3.name<<"\t\t"<<dish3.category<<"\t\t"<<dish3.veg_non<<"\t\t\tRs."<<dish3.price<<endl;

  cout<<"4.\t"<<dish4.name<<"\t\t"<<dish4.category<<"\t\t"<<dish4.veg_non<<"\t\t\tRs."<<dish4.price<<endl;

  cout<<"5.\t"<<dish5.name<<"\t\t"<<dish5.category<<"\t\t"<<dish5.veg_non<<"\t\t\tRs."<<dish5.price<<endl;

  cout<<"6.\t"<<dish6.name<<"\t\t"<<dish6.category<<"\t\t"<<dish6.veg_non<<"\t\t\tRs."<<dish6.price<<endl;

  cout<<"7.\t"<<dish7.name<<"\t\t"<<dish7.category<<"\t\t"<<dish7.veg_non<<"\t\t\tRs."<<dish7.price<<endl;

  cout<<"8.\t"<<dish8.name<<"\t\t"<<dish8.category<<"\t\t"<<dish8.veg_non<<"\t\t\tRs."<<dish8.price<<endl;

  cout<<"9.\t"<<dish9.name<<"\t\t"<<dish9.category<<"\t\t"<<dish9.veg_non<<"\t\t\tRs."<<dish9.price<<endl;
  cout<<"Press 10 to print Final Bill.";
  cout<<"Press 0 to exit"<<endl;

  order o;
  o.ordering(dish1, dish2, dish3, dish4, dish5, dish6, dish7,dish8, dish9 );
}
