Strukture podataka projekat, Grupa 3
Uvod
Klase i funkcije sadržane u projektnom folderu služe za upravljanje jednostavnom bazom podataka koja sadrži informacije o nastavnom osoblju, studentima, odsjecima i predmetima na nekoj visokoškolskoj obrazovnoj ustanovi. 
U projektnom direktoriju razlikujemo tri pod-direktorija : api, db i dto. 
U api direktoriju su sadržane klase, strukture i funkcije neophodne za rad sa bazom podataka.
U odt direktoriju su smještene strukture koje prihvataju podatke iz txt fileova prilikom izvršavanja programa koji koristi interface obezbijeđen gore navedenim. 
U db direktoriju su smješteni txt file-ovi koji cuvaju podatke u sekundarnoj memoriji. 


Specifikacija interface-a 


Za uspostavljanje pozadinske strukture koja upravlja bazom podataka neophodno je kreirati instance objekata klasa studentapi, teacherapi, subjectapi i department api (sadržanih u APIs.h) , te izvršiti poziv funkcije connect, koja prima reference spomenutih objekata (potpis funkcije : connect(studentapi&, teacherapi&, subjectapi&,departmentapi&)).


Preko funkcije update, vrsi se upis promjena izvrsenih nad bazom podataka u txt fileove (potpis funkcije: update(studentapi&, teacherapi&, subjectapi&,departmentapi&)).


Svaka od klasa iz APIs.h zaglavlja pruža mogućnosti dodavanja novih objekata odgovarajućeg tipa putam metoda save, kao i njihovog otklanjanja putem metoda Remove.
Takođe su obezbjeđeni metodi za pristup pojedinačnim članovima sadržanim u klasi (getById) i pristup svim članovima sadržanim u klasi (getAll). Otklanjanje objekata, kao i pristup pojedinacnim objektima se vrsi po ID-u. U slučaju da objekat koji se zahtijeva po ID-u ne postoji, prikazuju se adekvatne poruke. U svakoj od klasa iz odt foldera postoji i metod debug_print koji sluzi za ispisivanje svih clanova odredjene klase zbog provjeravanja informacija.
Svaka od klasa sadrži i određene unikatne metode, koje su izlistane ispod:


Departmentapi: 
getSubjects(unsigned int) - ispisuje sve predmete sa odsjeka sa odgovarajucim ID-em, ukoliko postoji.


Subjectapi:
getStudents(unsigned int) - ispisuje sve studente koji slusaju odredjeni predmet, ukolikopostoji.
getTeachers(unsigned int) - ispisuje sve profesore koji drže odredjeni predmet, ukoliko postoji.
addTeacher(unsigned int,unsigned int,const std::string&,const std::string&,const std::string&,
const std::string&,char,const std::string&,unsigned int,const std::string&) - dodaje profesora odredjenom predmetu.
connectSubjDep(unsigned int, unsigned int) - vrsi povezivanje predmeta sa departmentom, ukoliko oba postoje.
connectSubjTeach(unsigned int, unsigned int) - vrsi povezivanje profesora i predmeta, ukoliko oba postoje. 


Studentapi:
passedExams(unsigned int) - ispisuje sve ispite koje je odredjeni student polozio.
getSubjects(unsigned int) - ispisuje sve predmete koje odredjeni student slusa, ukoliko postoji.
changeLastName(unsigned int, const std::string&) - mijenja prezime odredjenog studenta, ukoliko postoji.


Teacherapi:
changeLastName(unsigned int, const std::string&) - mijenja prezime odredjenog profesora ako postoji.
changeTitle(unsigned int,const std::string&) - mijenja titulu odredjenog profesora ako postoji.
changeDep(unsigned int,unsigned int) - mijenja department odredjenog profesora ako postoji department.
getSub(unsigned int) - ispisuje sve predmete koji odredjeni profesor drzi. Ukoliko postoji.
