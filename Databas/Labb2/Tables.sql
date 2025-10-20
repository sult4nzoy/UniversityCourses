CREATE TABLE Hospital
(
	Name VARCHAR(255),
    HospitalID INT NOT NULL,                  
    PhoneNumber VARCHAR(255),
    Adress VARCHAR(255),
    State VARCHAR(255),
    City VARCHAR(255),
    Zip VARCHAR(255)
);


CREATE TABLE Employee
(
	EmployeeID INT NOT NULL,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    Degree VARCHAR(255),
    HireDate DATE,
    Adress VARCHAR(255),
    Zip VARCHAR(255),
	City VARCHAR(255),
    HomePhone VARCHAR(255),
    HospitalID INT NOT NULL
);

CREATE TABLE Customer
(
    Name VARCHAR(255),
	PhoneNumber VARCHAR(255),
    CustomerID INT NOT NULL,
    TypeOfCustomer VARCHAR(255),
    Adress VARCHAR(255),
    Zip VARCHAR(255),
    State VARCHAR(255),
    City VARCHAR(255),
    FaxNumber VARCHAR(255)
);

CREATE TABLE Pet
(
	TypeOfAnimal VARCHAR(255),
    Gender VARCHAR(255),
    Breed VARCHAR(255),
    DoB DATE,
    PetID INT NOT NULL,
    PetName VARCHAR(255),
    CustomerID INT NOT NULL
);

CREATE TABLE Visit
(
	VisitID INT NOT NULL,
    VisitDate DATE
);

CREATE TABLE Service
(
	ServiceID INT NOT NULL,
    Price FLOAT NOT NULL,	
    Treatment VARCHAR(255)
);