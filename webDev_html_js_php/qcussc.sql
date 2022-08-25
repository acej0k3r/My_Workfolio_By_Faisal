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

ALTER TABLE AdminSubmits
ADD FormID INT;

ALTER  TABLE AdminSubmits
ADD FOREIGN KEY (FormID) REFERENCES Forms(FormID);


INSERT INTO Administrator() VALUES(1001, 'John Smith', '212-278-9675', 'john.smith@qc.cuny.edu', 'john01','Smith-John2021');
INSERT INTO Administrator() VALUES(1002, 'Amanda Lee', '917-260-0996', 'amanda.lee@qc.cuny.edu', 'amanda02','Amanda-Lee2021');
INSERT INTO Administrator() VALUES(1003, 'Mario Lopez', '347-512-6009', 'mario.lopez@qc.cuny.edu', 'mario03','Lopez-mario2021');
INSERT INTO Administrator() VALUES(1004, 'Mike Johnson', '646-215-9660', 'mike.johnson@qc.cuny.edu', 'mike04','Johnson-mike2021');
INSERT INTO Administrator() VALUES(1005, 'Jessica Liu', '580-208-9960', 'jessica.Liu@qc.cuny.edu', 'jessica05','Liu-Jessica2021');
INSERT INTO Administrator() VALUES(1006, 'Prakash Patel', '425-316-9990', 'Prakash.patel@qc.cuny.edu', 'prakash06','Prakash-patel2020');
INSERT INTO Administrator() VALUES(1007, 'Mikito Sinatra', '254-452-6660', 'mikito.sinatra@qc.cuny.edu', 'mikito07','Mikito-Sinatra2021');
INSERT INTO Administrator() VALUES(1008, 'Roni Ahmed', '718-346-4440', 'roni.ahmed@qc.cuny.edu', 'roni08','Ahmed-Roni2021');
INSERT INTO Administrator() VALUES(1009, 'Rachel Chang', '607-397-1245', 'rachel.chang@qc.cuny.edu', 'rachel09','Rachel-chang2021');
INSERT INTO Administrator() VALUES(1010, 'Leslie Jimenez', '631-509-4214', 'leslie.jimenez@qc.cuny.edu', 'leslie10','Jimenez-Leslie2021');
INSERT INTO Administrator() VALUES(1011, 'Julia Roberts', '716-912-6513', 'julia.roberts@qc.cuny.edu', 'julia11','Roberts-Julia2021');
INSERT INTO Administrator() VALUES(1012, 'Jasmine Gupta', '315-904-9012', 'jasmine.gupta@qc.cuny.edu', 'jasmine12','Gupta-jasmine2021');


INSERT INTO Staffs() VALUES(3001, 'Juan Gonzalez', '347-278-9675', 'juan.gonzalez@qc.cuny.edu', 'juan01','Juan-Gonzalez2021');
INSERT INTO Staffs() VALUES(3002, 'Mary Poppins', '646-260-0996', 'mary.poppins@qc.cuny.edu', 'mary02','Amanda-Poppins2021');
INSERT INTO Staffs() VALUES(3003, 'Carlos Gomez', '212-512-6009', 'carlos.gomez@qc.cuny.edu', 'carlos03','Lopez-Gomez2021');
INSERT INTO Staffs() VALUES(3004, 'Michael Brown', '917-215-9660', 'michael.brown@qc.cuny.edu', 'michael04','Michael-Brown2021');
INSERT INTO Staffs() VALUES(3005, 'Jennifer Chen', '718-208-9960', 'jennifer.chen@qc.cuny.edu', 'jennifer05','Chen-Jennifer2021');
INSERT INTO Staffs() VALUES(3006, 'Sanjay Singhania', '212-316-9990', 'sanjay.singhania@qc.cuny.edu', 'Sanjay06','Sanjay-Singhania2021');
INSERT INTO Staffs() VALUES(3007, 'Maiko Nakamura', '646-452-6660', 'maiko.nakamura@qc.cuny.edu', 'Maiko07','Maiko-Nakamura2021');
INSERT INTO Staffs() VALUES(3008, 'MD Abdul', '714-346-4440', 'md.abdul@qc.cuny.edu', 'roni08','Abdul-md2021');
INSERT INTO Staffs() VALUES(3009, 'Rose Li', '352-397-1245', 'rose.li@qc.cuny.edu', 'Rose09','Rose-Li2021');
INSERT INTO Staffs() VALUES(3010, 'Lorraine Rosenfeld', '716-509-4214', 'lorraine.rosenfeld@qc.cuny.edu', 'Lorraine10','Lorraine-Rosenfeld2021');
INSERT INTO Staffs() VALUES(3011, 'Angela Gustavo', '315-912-6513', 'angela.gustavo@qc.cuny.edu', 'Angela11','Angela-Gustavo2021');
INSERT INTO Staffs() VALUES(3012, 'Sofia Chopra', '718-904-9012', 'sofia.chopra@qc.cuny.edu', 'Sofia12','Sofia-Chopra2021');


INSERT INTO Students() VALUES(3001, 'Valeria Gonzalez', '123 Main street Flushing', '347-278-0996', 'juan.gonzalez@qc.cuny.edu', 'juan01','Juan-Gonzalez2021');
INSERT INTO Students() VALUES(3002, 'Mary Jones', '100 Queens Blvd East Elmhurst','646-260-6009', 'mary.poppins@qc.cuny.edu', 'mary02','Amanda-Poppins2021');
INSERT INTO Students() VALUES(3003, 'Victor alba','400 Canal street College Point', '917-512-9660', 'carlos.gomez@qc.cuny.edu', 'carlos03','Lopez-Gomez2021');
INSERT INTO Students() VALUES(3004, 'Matthew Jones', '252 battery street New York','718-215-9960', 'michael.brown@qc.cuny.edu', 'michael04','Michael-Brown2021');
INSERT INTO Students() VALUES(3005, 'Yeoun Kim', '600 Broadway  Elmhurst','212-208-9999', 'jennifer.chen@qc.cuny.edu', 'jennifer05','Chen-Jennifer2021');
INSERT INTO Students() VALUES(3006, 'Sanjay Singhania', '7444 76 street Jackson Heights','646-316-6660', 'sanjay.singhania@qc.cuny.edu', 'Sanjay06','Sanjay-Singhania2021');
INSERT INTO Students() VALUES(3007, 'Yifu Chan', '231 Northern blvd Whitestone','714-452-4440', 'maiko.nakamura@qc.cuny.edu', 'Maiko07','Maiko-Nakamura2021');
INSERT INTO Students() VALUES(3008, 'Rahat Khan', '712 63rd avenue street Forest Hills','352-346-1245', 'md.abdul@qc.cuny.edu', 'roni08','Abdul-md2021');
INSERT INTO Students() VALUES(3009, 'Rose Park', '546 West 23rd street Chelsea','716-397-4214', 'rose.li@qc.cuny.edu', 'Rose09','Rose-Li2021');
INSERT INTO Students() VALUES(3010, 'Lauren Rosenfeld','118 East 42nd street New York', '315-509-6513', 'lorraine.rosenfeld@qc.cuny.edu', 'Lorraine10','Lorraine-Rosenfeld2021');
INSERT INTO Students() VALUES(3011, 'Emma Watson', '7642 30 street Jamaica','718-912-9012', 'angela.gustavo@qc.cuny.edu', 'Angela11','Angela-Gustavo2021');
INSERT INTO Students() VALUES(3012, 'Sofia Chopra', '3030 50 street Ridgewood','712-904-9675', 'sofia.chopra@qc.cuny.edu', 'Sofia12','Sofia-Chopra2021');
INSERT INTO Students() VALUES(3013, 'Juan Garcia', '2930 179 street Long Island City','646-278-5689', 'juan.gonzalez@qc.cuny.edu', 'juan01','Juan-Gonzalez2021');
INSERT INTO Students() VALUES(3014, 'Mary Poppins', '5630 Queens Blvd  Astoria','212-260-3536', 'mary.poppins@qc.cuny.edu', 'mary02','Amanda-Poppins2021');
INSERT INTO Students() VALUES(3015, 'Samuel Gomez', '6412 11th Avenue Sunnyside','912-512-1872', 'carlos.gomez@qc.cuny.edu', 'carlos03','Lopez-Gomez2021');
INSERT INTO Students() VALUES(3016, 'David Miller', '300 East 14 street Corona','714-215-6364', 'michael.brown@qc.cuny.edu', 'michael04','Michael-Brown2021');
INSERT INTO Students() VALUES(3017, 'Jennifer Chen', '5263 27th Ave Woodside','716-208-1183', 'jennifer.chen@qc.cuny.edu', 'jennifer05','Chen-Jennifer2021');
INSERT INTO Students() VALUES(3018, 'Bilal Hassan', '5261 Broadway street Flushing','646-316-0193', 'sanjay.singhania@qc.cuny.edu', 'Sanjay06','Sanjay-Singhania2021');
INSERT INTO Students() VALUES(3019, 'Joseph Choe', '8152 63rd Drive Rego-Park', '917-452-6836', 'maiko.nakamura@qc.cuny.edu', 'Maiko07','Maiko-Nakamura2021');
INSERT INTO Students() VALUES(3020, 'Himal Khadka', '1783 85th street Bayside','352-346-2180', 'md.abdul@qc.cuny.edu', 'roni08','Abdul-md2021');
INSERT INTO Students() VALUES(3021, 'Rose Li', '7654 Queens Blvd  Jamaica','716-397-1095', 'rose.li@qc.cuny.edu', 'Rose09','Rose-Li2021');
INSERT INTO Students() VALUES(3022, 'Jasmine Williams', '5641 Park Avenue New York','347-509-1237', 'lorraine.rosenfeld@qc.cuny.edu', 'Lorraine10','Lorraine-Rosenfeld2021');
INSERT INTO Students() VALUES(3023, 'Prescilla Santiago', '862 5th Aenue New York','580-912-2535', 'angela.gustavo@qc.cuny.edu', 'Angela11','Angela-Gustavo2021');
INSERT INTO Students() VALUES(3024, 'Isabella Cavil', '3012 Northern Blvd East Elmhurst','718-904-2834', 'sofia.chopra@qc.cuny.edu', 'Sofia12','Sofia-Chopra2021');
INSERT INTO Students() VALUES(3025, 'Harry porter', '252 7th Ave Chelsea','718-409-5628', 'harry.porter@qc.cuny.edu', 'harry25','Harry-Porter2021');

INSERT INTO Courses() VALUES(100, 'CSCI 111', 'Introduction to Algorithmic Problem Solving', 3, 'M/W 9:15 Am - 10:30 Am', 'Online', null, 3001 );
INSERT INTO Courses() VALUES(101, 'CSCI 211', 'Object-Oriented Programming in C++', 3, 'M/W 08:00 Pm - 09:15 Pm', 'Online', null, 3002 );
INSERT INTO Courses() VALUES(102, 'CSCI 212', 'Object-Oriented Programming in Java', 3, 'M/W 3:10 Pm - 4:35 Pm', 'Online', null, 3003 );
INSERT INTO Courses() VALUES(103, 'CSCI 220', 'Discrete Structures', 3, 'TU/TH 9:15 Am - 10:30 Am', 'Online', null, 3004 );
INSERT INTO Courses() VALUES(104, 'CSCI 240', 'Computer Organization and Assembly Language', 3, 'TU/TH 3:10 Pm - 4:25 Pm', 'Online', null, 3005 );
INSERT INTO Courses() VALUES(105, 'CSCI 313', 'Data Structures', 3, 'TU/TH 08:00 Pm - 09:15 Pm', 'Online', null, 3006 );
INSERT INTO Courses() VALUES(106, 'CSCI 320', 'Theory of Computation', 3, 'M/W 9:15 Am - 10:30 Am', 'Online', null, 3007 );
INSERT INTO Courses() VALUES(107, 'CSCI 323', 'Design and Analysis of Algorithms', 3, 'M/W 08:00 Pm - 09:15 Pm', 'Online', null, 3008 );
INSERT INTO Courses() VALUES(108, 'CSCI 331', 'Database Systems', 3, 'TU/TH 3:10 Pm - 4:25 Pm', 'Online', null, 3009 );
INSERT INTO Courses() VALUES(109, 'CSCI 340', 'Operating System', 3, 'M/W 9:15 Am - 10:30 Am', 'Online', null, 3010 );
INSERT INTO Courses() VALUES(110, 'CSCI 343', 'Computer Architecture', 3, 'TU/TH 9:15 Am - 10:30 Am', 'Online', null, 3001 );
INSERT INTO Courses() VALUES(111, 'CSCI 355', 'Internet and Web Technology', 3, 'TU/TH 08:00 Pm - 09:15 Pm', 'Online', null, 3002 );
INSERT INTO Courses() VALUES(112, 'CSCI 370', 'Software Engineering', 3, 'TU/TH 3:10 Pm - 4:25 Pm', 'Online', null, 3003 );
INSERT INTO Courses() VALUES(113, 'CSCI 316', 'Principles of Programming Languages', 3, 'M/W 08:00 Am - 09:15 Am', 'Online', null, 3004 );
INSERT INTO Courses() VALUES(114, 'CSCI 381', 'Special Topics in Computer Science', 3, 'M/W 3:10 Pm - 4:35 Pm', 'Online', null, 3005 );
INSERT INTO Courses() VALUES(115, 'CSCI 352', 'Cryptography', 3, 'M/W 08:00 Pm - 09:15 Pm', 'Online', null, 3006 );
INSERT INTO Courses() VALUES(116, 'MATH 120', 'Discrete Math', 3, 'M/W 9:15 Am - 10:30 Am', 'Online', null, 3011 );
INSERT INTO Courses() VALUES(117, 'MATH 151', 'Calculus I', 4, 'M/W 08:00 Pm - 09:15 Pm', 'Online', null, 3012 );
INSERT INTO Courses() VALUES(118, 'MATH 152', 'Calculus II', 4, 'TU/TH 9:15 Am - 10:30 Am', 'Online', null, 3011 );
INSERT INTO Courses() VALUES(119, 'MATH 231', 'Linear algebra', 4, 'M/W 3:10 Pm - 04:25 Pm', 'Online', null, 3012 );
INSERT INTO Courses() VALUES(120, 'MATH 240', 'Probability and Statistics', 3, 'TU/TH 03:15 Pm - 04:25 Pm', 'Online', null, 3011);
INSERT INTO Courses() VALUES(121, 'MATH 333', 'Abstract algebra', 3, 'TU/TH 08:00 Pm - 09:15 Pm', 'Online', null, 3012);

INSERT INTO StudentCourseHistory() VALUES(400, 3001, 100, 3001, 'Fall 2020', 'A+');
INSERT INTO StudentCourseHistory() VALUES(401, 3002, 101, 3002, 'Spring 2020', 'A-');
INSERT INTO StudentCourseHistory() VALUES(402, 3003, 102, 3003, 'Fall 2019', 'WN');
INSERT INTO StudentCourseHistory() VALUES(403, 3004, 103, 3004, 'Spring 2019', 'A-');
INSERT INTO StudentCourseHistory() VALUES(404, 3005, 104, 3005, 'Summer 2020', 'B+');
INSERT INTO StudentCourseHistory() VALUES(405, 3006, 105, 3006, 'Fall 2019', 'C+');
INSERT INTO StudentCourseHistory() VALUES(406, 3007, 106, 3007, 'Spring 2019', 'F');
INSERT INTO StudentCourseHistory() VALUES(407, 3008, 107, 3008, 'Summer 2018', 'A+');
INSERT INTO StudentCourseHistory() VALUES(408, 3009, 108, 3009, 'Fall 2020', 'A-');
INSERT INTO StudentCourseHistory() VALUES(409, 3010, 109, 3001, 'Spring 2019', 'WN');
INSERT INTO StudentCourseHistory() VALUES(410, 3011, 110, 3002, 'Summer 2018', 'W');
INSERT INTO StudentCourseHistory() VALUES(411, 3012, 100, 3001, 'Winter 2020', 'C+');
INSERT INTO StudentCourseHistory() VALUES(412, 3013, 101, 3002, 'Fall 2019', 'B+');
INSERT INTO StudentCourseHistory() VALUES(413, 3014, 102, 3003, 'Spring 2020', 'A-');
INSERT INTO StudentCourseHistory() VALUES(414, 3015, 103, 3004, 'Summer 2020', 'A');
INSERT INTO StudentCourseHistory() VALUES(415, 3016, 104, 3005, 'Fall 2019', 'B');
INSERT INTO StudentCourseHistory() VALUES(416, 3001, 117, 3012, 'Winter 2020', 'C');
INSERT INTO StudentCourseHistory() VALUES(417, 3002, 118, 3011, 'Spring 2019', 'F');
INSERT INTO StudentCourseHistory() VALUES(418, 3003, 119, 3012, 'Summer 2018', 'A');
INSERT INTO StudentCourseHistory() VALUES(419, 3004, 120, 3011, 'Spring 2018', 'WN');
INSERT INTO StudentCourseHistory() VALUES(420, 3005, 121, 3012, 'Summer 2019', 'A+');
INSERT INTO StudentCourseHistory() VALUES(421, 3006, 101, 3002, 'Winter 2019', 'A-');
INSERT INTO StudentCourseHistory() VALUES(422, 3007, 102, 3003, 'Spring 2020', 'B+');
INSERT INTO StudentCourseHistory() VALUES(423, 3008, 103, 3004, 'Summer 2020', 'C+');
INSERT INTO StudentCourseHistory() VALUES(424, 3009, 104, 3005, 'Fall 2020', 'B-');
INSERT INTO StudentCourseHistory() VALUES(425, 3010, 105, 3006, 'Fall 2019', 'B');
INSERT INTO StudentCourseHistory() VALUES(426, 3011, 106, 3007, 'Spring 2020', 'A');
INSERT INTO StudentCourseHistory() VALUES(427, 3012, 107, 3008, 'Winter 2020', 'A');
INSERT INTO StudentCourseHistory() VALUES(428, 3013, 108, 3009, 'Summer 2020', 'W');
INSERT INTO StudentCourseHistory() VALUES(429, 3014, 109, 3010, 'Fall 2020', 'C+');
INSERT INTO StudentCourseHistory() VALUES(430, 3015, 110, 3001, 'Spring 2020', 'WN');
INSERT INTO StudentCourseHistory() VALUES(431, 3016, 115, 3006, 'Summer 2020', 'A');
INSERT INTO StudentCourseHistory() VALUES(432, 3016, 116, 3011, 'Fall 2020', 'A-');

INSERT INTO Forms() VALUES(700, 402);
INSERT INTO Forms() VALUES(701, 409);
INSERT INTO Forms() VALUES(702, 419);
INSERT INTO Forms() VALUES(703, 430);

INSERT INTO StudentRequest() VALUES(900, 3003, 700, '2021-01-25 09:15:40', null);
INSERT INTO StudentRequest() VALUES(901, 3010, 701, '2020-12-27 11:35:25',null);
INSERT INTO StudentRequest() VALUES(902, 3004, 702, '2021-02-18 15:07:18',null);
INSERT INTO StudentRequest() VALUES(903, 3015, 703, '2020-12-18 10:49:36',null);

INSERT INTO AdminSubmits() VALUES(800, 1001, 900, '2021-01-25 09:15:40', null, 700);
INSERT INTO AdminSubmits() VALUES(801, 1012, 901, '2020-12-27 11:35:25', null, 701);
INSERT INTO AdminSubmits() VALUES(802, 1009, 902, '2021-02-18 15:07:18', null, 702);
INSERT INTO AdminSubmits() VALUES(803, 1006, 903, '2020-12-18 10:49:36', null, 703);

INSERT INTO StaffReview() VALUES(600, 3003, 800, 700, 'Approved', '2021-02-05 10:15:40');
INSERT INTO StaffReview() VALUES(601, 3001, 801, 701, 'Pending', '2021-01-07 15:25:20');
INSERT INTO StaffReview() VALUES(602, 3011, 802, 702, 'Denied', '2021-02-28 13:35:45');
INSERT INTO StaffReview() VALUES(603, 3001, 803, 703, 'Approved', '2020-12-30 12:00:10');


