# insert hospital
INSERT INTO Hospital (Name, HospitalID, PhoneNumber, Adress, State, City, Zip) VALUES 
('Sundsvalls Sjukhus', 19000, '0708860164', 'Fredagsvägen 30', 'Västernorrland', 'Sundsvall', '86334'),
('Karolinska Universitetssjukhuset', 15000, '0852345600', 'Solnavägen 1', 'Stockholm', 'Stockholm', '17176'),
('Sahlgrenska Universitetssjukhuset', 17000, '0313421000', 'Blå Stråket 5', 'Västra Götaland', 'Göteborg', '41345'),
('Skånes Universitetssjukhus', 14000, '046171000', 'Entrégatan 7', 'Skåne', 'Lund', '22185'),
('Uppsala Akademiska Sjukhus', 12000, '0186115000', 'Sjukhusvägen 1', 'Uppsala', 'Uppsala', '75185');

# insert customer
INSERT INTO Customer (Name, PhoneNumber, CustomerID, TypeOfCustomer, Adress, Zip, State, City, FaxNumber) VALUES 
('Karl Johansson', '0708540542', 954, '1', 'Fröjdsgatan 456', '87654', 'Västernorrland', 'Stockholm', '300'),
('Johan Johansson', '0701234567', 955, '2', 'Storgatan 23', '86234', 'Västernorrland', 'Sundsvall', '301'),
('Jonna Andersson', '0709876543', 956, '2', 'Kyrkogatan 15', '87365', 'Västernorrland', 'Sundsvall', '302'),
('Emil Nordlander', '0705551234', 957, '1', 'Sjövägen 8', '86124', 'Västernorrland', 'Sundsvall', '303'),
('Henrik Henkesson', '0704445678', 958, '2', 'Skogsvägen 42', '87543', 'Västernorrland', 'Sundsvall', '304');

# insert visit
INSERT INTO Visit (VisitID, VisitDate) VALUES 
(456, '2025-09-24'),
(457, '2025-09-25'),
(458, '2025-10-01'),
(459, '2025-10-05'),
(460, '2025-10-12');

# insert service
INSERT INTO Service (ServiceID, Price, Treatment) VALUES 
(678, 13542, 'Anti-Flea'),
(679, 25750, 'Antibiotica'),
(680, 45000, 'Dental cleaning'),
(681, 15250, 'Health checkup'),
(682, 85500, 'Pencillin');

# insert employees
INSERT INTO Employee (EmployeeID, FirstName, LastName, Degree, HireDate, Adress, Zip, City, HomePhone, HospitalID) VALUES 
(999, 'John', 'Doe', 'Computer Science', '2025-09-23', 'Testgatan 123', '86543', 'Sundsvall', '060102051', 19000),
(3000, 'Omar', 'Sultanzoy', 'Computer Science', '2024-09-02', 'Fredagsvägen 30', '86335', 'Sundsvall', '0708860165', 19000),
(1000, 'Emma', 'Johnson', 'Mathematics', '2024-03-15', 'Storgatan 45', '11347', 'Stockholm', '0701234567', 15000),
(1001, 'Anders', 'Svensson', 'Physics', '2023-11-08', 'Kungsgatan 12', '41119', 'Göteborg', '0729876543', 17000),
(1002, 'Maria', 'Garcia', 'Biology', '2024-07-22', 'Strandvägen 78', '21774', 'Malmö', '0765551234', 14000),
(1003, 'David', 'Nilsson', 'Chemistry', '2023-05-30', 'Skogsvägen 3', '75331', 'Uppsala', '0734445678', 12000);


# insert pets
INSERT INTO Pet (TypeOfAnimal, Gender, Breed, DoB, PetID, PetName, CustomerID) VALUES 
('Cat', 'Male', 'Bengal', '2023-09-23', 123, 'Bobo', 954),
('Dog', 'Female', 'Golden Retriever', '2022-05-15', 124, 'Luna', 955),
('Dog', 'Male', 'Labrador', '2021-11-30', 125, 'Max', 956),
('Cat', 'Female', 'Siamese', '2023-03-10', 126, 'Molly', 957),
('Rabbit', 'Male', 'Holland Lop', '2024-01-20', 127, 'Bugs', 958);