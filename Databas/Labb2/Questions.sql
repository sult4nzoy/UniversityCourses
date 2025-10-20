
# Lista ut alla customers förutom CustomerID 958
SELECT * FROM Customer WHERE CustomerID != 958;

# Lista ut alla treatments som innehåller Stort A

SELECT * FROM Service WHERE Treatment LIKE 'A%';

# Lista ut alla employees som började mellan '2023-05-30' och '2024-07-22'

SELECT * FROM Employee WHERE HireDate BETWEEN '2023-05-30' AND '2024-07-22';

# Lista ut hur många employees som har en viss degree

SELECT Degree, COUNT(EmployeeID) AS NumberOfEmployees FROM Employee GROUP BY Degree;

# Lista ut hur många customers som har mer än 2 djur

SELECT CustomerID, COUNT(*) AS PetCount FROM Pet GROUP BY CustomerID HAVING COUNT(*) > 2;

# Sortera priserna i service. Billigast först. 

SELECT * FROM Service ORDER BY Price;

# Uppdatera namnet på ett djur från Bobo till Freddan

UPDATE Pet SET PetName = "Freddan" WHERE PetName = "Bobo";

# Lista ut avg priset av alla priser i service. Sedan vill jag ha priserna som är mindra än avg.

SELECT * FROM Service WHERE (SELECT AVG(Price) FROM Service) < Price;



