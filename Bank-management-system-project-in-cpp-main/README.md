# Bank-management-system-project-using-C++

The application **Control My Cash** is a Bank Management System designed for two categories of users: Employees and Customers.

## Features

### Customer Features:
- **Create Account**: Allows customers to create new accounts with their personal information.
- **Cash Out**: Enables customers to withdraw funds from their accounts.
- **Donate**: Facilitates donations from customer accounts for Palestine.
- **Send Money**: Permits customers to transfer funds to other accounts.
- **Apply for Loan**: Allows customers to submit loan applications.

#### View Options:
- **Transaction History**: Enables customers to review their past transactions.
- **Check Balance**: Allows customers to verify their account balance.
- **Contact for Help**: Provides a way for customers to reach out for assistance.

### Employee Features:
- **Insert Cash**: Allows employees to deposit funds into various customer accounts.
- **Update Information**: Enables employees to modify customer details such as name, age, and National Identity (NID).
- **Delete Account**: Permits employees to remove customer accounts.

#### View Options:
- **Search Account**: Enables employees to look up account details.
- **Check Account**: Allows employees to review account information.

## Login Information

### Customer Login:
- Requires phone number and password set by the customer.

### Employee Login:
- Uses fixed IDs and passwords:
  - ID: C233477, Password: yasup
  - ID: C233479, Password: xyz
  - ID: C233510, Password: EEEmate

## Data Storage

All data inserted and changes made are stored in a file named `user`. This ensures that all changes and newly created accounts remain accessible even after the code stops running.
## Important Note

The account balance will never be allowed to fall below `20`. If a user attempts to reduce the balance below this amount, the action will be stopped, and a warning will be given.

## Support
If you found our project helpful, we would greatly appreciate it if you could give us a star🌟It will help our project to reach more people
## Contributing

Contributions are always welcome!
