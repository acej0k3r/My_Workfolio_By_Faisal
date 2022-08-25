USE QCUSSC;

CREATE TABLE Students(
studentID INT PRIMARY KEY,
studentName VARCHAR(45),
studentAddress VARCHAR(45),
studentPhone VARCHAR(45),
studentEmail VARCHAR(45),
studentUsername VARCHAR(45),
studentPassword VARCHAR(45)
);

CREATE TABLE Staffs(
staffID INT PRIMARY KEY,
staffName VARCHAR(45),
staffPhone VARCHAR(45),
staffEmail VARCHAR(45),
staffUsername VARCHAR(45),
staffPassword VARCHAR(45)
);

CREATE TABLE Administrator(
adminID INT PRIMARY KEY,
adminName VARCHAR(45),
adminPhone VARCHAR(45),
adminEmail VARCHAR(45),
adminUsername VARCHAR(45),
adminPassword VARCHAR(45)
);

CREATE TABLE Courses(
courseID INT PRIMARY KEY,
courseNum VARCHAR(20),
courseDescription VARCHAR(45),
courseUnit TINYINT,
daysTime VARCHAR(45),
courseFormat VARCHAR(45),
roomNum VARCHAR(45),
staffID INT,
FOREIGN KEY (staffID) REFERENCES Staffs(staffID)
);

CREATE TABLE StudentCourseHistory(
SCH_ID INT PRIMARY KEY,
studentID INT,
courseID INT,
staffID INT,
semesterYear VARCHAR(20),
studentGrade VARCHAR(5),
FOREIGN KEY (studentID) REFERENCES Students(studentID),
FOREIGN KEY (courseID) REFERENCES Courses(courseID),
FOREIGN KEY (staffID) REFERENCES Staffs(staffID)
);

CREATE TABLE Forms(
FormID INT PRIMARY KEY,
SCH_ID INT,
FOREIGN KEY (SCH_ID) REFERENCES StudentCourseHistory(SCH_ID)
);

CREATE TABLE StudentRequest(
requestID INT PRIMARY KEY,
studentID INT,
FormID INT,
dateRequested DATETIME,
formStatus VARCHAR(10),
FOREIGN KEY (studentID) REFERENCES Students(studentID),
FOREIGN KEY (FormID) REFERENCES Forms(FormID)
);


CREATE TABLE AdminSubmits(
submitID INT PRIMARY KEY,
adminID INT,
requestID INT,
dateSubmitted DATETIME,
requestStatus VARCHAR(10),
FOREIGN KEY (adminID) REFERENCES Administrator(adminID),
FOREIGN KEY (requestID) REFERENCES StudentRequest(requestID)
);


CREATE TABLE StaffReview(
reviewID INT PRIMARY KEY,
staffID INT,
submitID INT,
FormID INT,
reviewStatus VARCHAR(10),
dateApproved DATETIME,
FOREIGN KEY (staffID) REFERENCES Staffs(staffID),
FOREIGN KEY (submitID) REFERENCES AdminSubmits(submitID),
FOREIGN KEY (FormID) REFERENCES Forms(FormID)
);




