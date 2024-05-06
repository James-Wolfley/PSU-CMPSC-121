#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int sQuantity = 0;
	//Using floats here is not ideal for calculations involving money and using a decimal type or using ints and converting only when displaying is a much better idea.
	//Floating point errors when used in financial applications can result in quite serious issues. I am only using floats due to limitations in the activity.
	float price, commision, salePrice;

	cout << "Enter the number of shares purchased, purchase price of the stock, commission rate and sale price separated by a space.\nExample - (1000 45.76 .02 57.23)\n";
	cin >> sQuantity >> price >> commision >> salePrice;

	float totalBuyPrice = sQuantity * price;
	float buyCom = totalBuyPrice * commision;
	float totalSellPrice = sQuantity * salePrice;
	float sellCom = totalSellPrice * commision;

	//formatting numbers
	int totalW = 50;
	int stringW = 35;
	int numberW = totalW - stringW - 1;

	

	cout << fixed << setprecision(2);
	cout << setw(totalW) << "\n   ********* TRANSACTION DETAILS *********   ";
	cout << setw(stringW) << left << "\nCost of stock before commision" << right << setw(1) << "$" << setw(numberW) << totalBuyPrice;
	cout << setw(stringW) << left << "\nCommision on purchase" << right << setw(1) << "$" << setw(numberW) << buyCom;
	cout << setw(stringW) << left << "\nTotal cost of purchase" << right << setw(1) << "$" << setw(numberW) << buyCom + totalBuyPrice;
	cout << endl;
	cout << setw(stringW) << left << "\nSale revenue before commission" << right << setw(1) << "$" << setw(numberW) << totalSellPrice;
	cout << setw(stringW) << left << "\nCommission on sale" << right << setw(1) << "$" << setw(numberW) << sellCom;
	cout << setw(stringW) << left << "\nSale revenue after commision" << right << setw(1) << "$" << setw(numberW) << totalSellPrice - sellCom;
	cout << endl;
	cout << setw(stringW) << left << "\nProfit or loss on sale" << right << setw(1) << "$" << setw(numberW) << totalSellPrice - totalBuyPrice - sellCom - buyCom;

}




/*
Enter the number of shares purchased, purchase price of the stock, commission rate and sale price separated by a space.
Example - (1000 45.76 .02 57.23)
1000 45.76 .02 57.23

   ********* TRANSACTION DETAILS *********
Cost of stock before commision    $      45760.00
Commision on purchase             $        915.20
Total cost of purchase            $      46675.20

Sale revenue before commission    $      57230.00
Commission on sale                $       1144.60
Sale revenue after commision      $      56085.40

Profit or loss on sale            $       9410.20
*/