#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

const int MAX = 20;

class RetailItem
{private:
    std::string description;
    double price;
    int unitsOnHand;
    int reorderQuantity;
public:
    RetailItem()
    {
        description="";
        price=0.0;
        unitsOnHand=0;
        reorderQuantity=0;
    }
    RetailItem(std::string description,double price,int unitsOnHand,int reorderQuantity)
    {
        this->description=description;
        this->price=price;
        this->unitsOnHand=unitsOnHand;
        this->reorderQuantity=reorderQuantity;
    }
    void setPrice(double retailPrice){price=retailPrice;}
    void setUnitsOnHand(int retailUnitsOnHand){unitsOnHand=retailUnitsOnHand;}
    void setReorderQuantity(int retailReorderQuantity){reorderQuantity=retailReorderQuantity;}

    double getPrice(){return price;}
    int getUnitsOnHand(){return unitsOnHand;}
    int getReorderQuantity(){return reorderQuantity;}
    std::string getDescription(){return description;}

    void addInventory(RetailItem inventory[], int &inventoryCount){

        std::cout<<"Please describe the item: ";
        std::getline(std::cin >> std::ws, description);
            while(description.empty()|| std::cin.fail() || std::any_of(description.begin(), description.end(), [](char c) { return std::isdigit(c); }))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout<<"\nThat is not a valid option. Please try again.";
            std::cout<<"Please describe the item: ";
			std::getline(std::cin, description);

		}

        std::cout<<"Please enter the price: ";
        std::cin>>price;
             while(price <0 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout<<"\nThat is not a valid option. Please try again.";
            std::cout<<"Please enter the price: ";
            std::cin>>price;

		}

        std::cout<<"How many units? ";
        std::cin>>unitsOnHand;
             while(unitsOnHand <0 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout<<"\nThat is not a valid option. Please try again.";
            std::cout<<"How many units? ";
            std::cin>>unitsOnHand;

		}

        std::cout<<"What's the reorder quantity? ";
        std::cin>>reorderQuantity;

        inventory[inventoryCount] = RetailItem(description, unitsOnHand, price, reorderQuantity);
        inventoryCount++;
             while(reorderQuantity <0|| std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout<<"\nThat is not a valid option. Please try again.";
            std::cout<<"What's the reorder quantity? ";
            std::cin>>reorderQuantity;

		}


            if (inventoryCount >= MAX) {
        std::cout << "Inventory is full. Cannot add more items.";
    }
    }



    void displayInventory(RetailItem inventory[], int inventoryCount){

    if(inventoryCount==0)
        {
            std::cout << "Inventory is empty.";
            return;
        }
        for(int i=0;i<inventoryCount;i++)
        {
    std::cout<<"\nThis is the description: "<<inventory[i].getDescription()<<"\n";
    std::cout<<"This is the price: "<<inventory[i].getPrice()<<"\n";
    std::cout<<"This is the units on hand: "<<inventory[i].getUnitsOnHand()<<"\n";
    std::cout<<"This is the reorder quantity: "<<inventory[i].getReorderQuantity()<<"\n";
        }

    }

    void checkInventory(RetailItem inventory[], int inventoryCount){

        std::string description;
        bool check=false;

    std::cout<<"Which item do you want to check from inventory? ";
    std::getline(std::cin >> std::ws, description);
        if(inventoryCount==0)
        {
            std::cout << "Inventory is empty.";
            return;
        }

    for(int i=0;i<inventoryCount;i++){
        if(inventory[i].getDescription()==description){
            check=true;
            break;
        }
    }

    if(check)
        std::cout<<"Item is found in Inventory.";
    else
        std::cout<<"Item is not found in Inventory";



    }

    void displayReorder (RetailItem inventory[], int inventoryCount){

    if(inventoryCount==0)
        {
            std::cout << "Inventory is empty.";
        }
    std::cout<<"Displaying items that need be reordered:\n";

            for(int i=0;i<inventoryCount;i++)
        {
            if(inventory[i].getReorderQuantity()>0)
            {
            std::cout<<"\nThis is the description: "<<inventory[i].getDescription()<<"\n";
            std::cout<<"This is the price: "<<inventory[i].getPrice()<<"\n";
            std::cout<<"This is the units on hand: "<<inventory[i].getUnitsOnHand()<<"\n";
            std::cout<<"This is the reorder quantity: "<<inventory[i].getReorderQuantity()<<"\n";
            }

        }
        if(reorderQuantity==0)
            std::cout<<"\nNo items to be reordered";

    }

    void updateInventory(RetailItem inventory[], int inventoryCount){

            std::string description;
            int i;

            if (inventoryCount == 0)
            {
                std::cout<<"\nNo item to update";
            }
        else{

        std::cout<<"What should be updated?";
        std::getline(std::cin >> std::ws, description);


		for(i=0;i<inventoryCount;i++){
            if(inventory[i].getDescription()==description)
                break;
		}
		 std::cout<<"Please enter the price: ";
        std::cin>>price;

        std::cout<<"How many units? ";
        std::cin>>unitsOnHand;

        std::cout<<"What's the reorder quantity? ";
        std::cin>>reorderQuantity;

        inventory[i] = RetailItem(description, unitsOnHand, price, reorderQuantity);
        inventoryCount++;
        }

            if (inventoryCount >= MAX) {
        std::cout << "Inventory is full. Cannot add more items.";
    }

    }
};
int retailMenu();
int main()
{
    RetailItem inventory[MAX];
    int inventoryCount=0;
    RetailItem aRetailItem;

int choice;
    std::cout<<"Welcome to your retail inventory\n";

    while(choice!=6)
          {
              choice=retailMenu();
            if(choice==1)
                aRetailItem.addInventory(inventory, inventoryCount);
            else if (choice==2)
                aRetailItem.displayInventory(inventory, inventoryCount);
            else if (choice==3)
                aRetailItem.checkInventory(inventory, inventoryCount);
            else if (choice==4)
                aRetailItem.displayReorder(inventory, inventoryCount);
            else if (choice==5)
                aRetailItem.updateInventory(inventory, inventoryCount);


          }




return 0;
}


int retailMenu()
{
    int choice;
    std::cout<<"\nPlease choose an option:\n";
    std::cout<<"1) Add an item to inventory\n";
    std::cout<<"2) Display all items in inventory\n";
    std::cout<<"3) Check to see if an item is in inventory\n";
    std::cout<<"4) Display only those items that need to be re-ordered\n";
    std::cout<<"5) Update an item in inventory\n";
    std::cout<<"6) Exit\n";

    std::cin>>choice;

      while((choice < 1 || choice > 6) || std::cin.fail()){
    	std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nThat is not a valid option. Please try again.";
        std::cout<<"Please choose an option:\n";
        std::cout<<"1) Add an item to inventory\n";
        std::cout<<"2) Display all items in inventory\n";
        std::cout<<"3) Check to see if an item is in inventory\n";
        std::cout<<"4) Display only those items that need to be re-ordered\n";
        std::cout<<"5) Update an item in inventory\n";
        std::cout<<"6) Exit\n";

        std::cin>>choice;
      }
    return choice;
}
