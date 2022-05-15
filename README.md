# ShoppingCart

OOPS is used for creating classes and objects

This is Backend Implementation of Shopping-Cart where the user can select from a list of Products and add it to the cart and subsequently checkout from shopping

Product Class has entitites namely:  
1)Id  
2)Name  
3)Price  

Item Class has entitites namely:  
1)Product  
2)Quantity  
3)Price (total)  

Cart Class has entitites namely:  
1)Items  
2)Total  

Mapping:  
There is a 1:1 mapping between Product and Item that is each Item will refer to one unique Product  
There is N:1 mapping between Items and Cart as a Cart can have 'n' number of same items  

Data Structures Used are :  
List - For showing the available products  
Unordered Map - For checking if the product is already in the Cart (increase quantity by 1) OR we have to add a new Product in the Cart  

For Searching with the keyword (which is the first letter of the Product) I have used Linear Search because to view the Products the time complexity is already O(n) hence we cannot lower our search time complexity below O(n)  

HAPPY SHOPPING
