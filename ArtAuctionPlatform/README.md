1. Information about users is in a text file. Each user has a name (string), an id (int) and at type (this can be "collector" or "administrator"). This file is manually created, and it is read when the application starts.
2. Another file contains information about the items. Each item has a name (string), a category (string), the current price (int) and the list of offers (tuples <user id, date, offered sum>). These are read when the application starts.
3. When the application is launched, a new window is created for each user, having as title the user's name. The window will show all items (name, category, current price), sorted by current price.
4. A combo box will be populated with all categories and will allow the users to see only the items in the selected category.
5. Administrators can add new items, by inputting all the required information. Display an error if the name is empty or if the current price is zero or negative.
6. When selecting an item, another list will show all offers for that item, sorted descending by date.
7. Collectors can bid for a selected item. After bidding, the item's current price is updated to the offered sum, the new offer is added to the item's list of offers and the list of items will still be sorted by current price. Display an error if the offered sum is less than the item's current price.
8. When a modification is made by any user, all the other users will see the modified list of items. Use the Observer design pattern.
9. When the application finishes, all items are saved to the file.
