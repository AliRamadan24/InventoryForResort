# InventoryForResort
This C++ inventory management system is designed for tracking and managing retail stock in a resort setting. It utilizes a menu-driven interface to facilitate user interaction, allowing for the efficient organization of inventory data. The program is built around a RetailItem class, which encapsulates item attributes such as description, price, available stock, and reorder thresholds. Inventory data is stored in an array of objects, enabling structured management and retrieval of information.

The system ensures data integrity through input validation, preventing invalid entries such as negative values or empty descriptions. It also incorporates search and update functionalities, allowing users to modify existing records seamlessly. By monitoring stock levels and identifying items that require replenishment, the program helps maintain optimal inventory control, ensuring that essential items remain available. Designed for simplicity and efficiency, this system provides a practical solution for inventory tracking in a retail or resort environment.

Key Features:
Add an item to inventory – Users enter item details (description, price, units on hand, reorder quantity).
Display inventory – Lists all items stored in the system.
Check inventory – Searches for an item by description.
Display items needing reorder – Shows items with low stock.
Update an item – Modifies existing inventory data.
Exit the program – Terminates execution.
The program uses a RetailItem class to encapsulate item properties and functions, and it supports user interaction through a menu-driven system.
