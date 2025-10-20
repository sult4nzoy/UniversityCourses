# Definera primärnycklarna: 
ALTER TABLE Hospital ADD CONSTRAINT PK_Hospital PRIMARY KEY (HospitalID);

ALTER TABLE Employee ADD CONSTRAINT PK_Employee PRIMARY KEY (EmployeeID);

ALTER TABLE Customer ADD CONSTRAINT PK_Customer PRIMARY KEY (CustomerID);

ALTER TABLE Pet ADD CONSTRAINT PK_Pet PRIMARY KEY (PetID);

ALTER TABLE Visit ADD CONSTRAINT PK_Visit PRIMARY KEY (VisitID);

ALTER TABLE Service ADD CONSTRAINT PK_Service PRIMARY KEY (ServiceID);


# Definera främmande nycklarna: 
ALTER TABLE Employee ADD CONSTRAINT FK_Hospital_Employee FOREIGN KEY (HospitalID) REFERENCES Hospital (HospitalID);

ALTER TABLE Pet ADD CONSTRAINT FK_Customer_Pet FOREIGN KEY (CustomerID) REFERENCES Customer (CustomerID);
