
#include "SFML.h"
string Okno::markPassword(string pass)
{
    for (int i = 0; i < pass.length(); i++) {
        if (pass.length() == 0) {
            break;
        }
        else {
            pass[i] = '*';
        }
    }
    return pass;
}
void Okno::SetTexts()
{

    text.setString("System bankowy");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(100);
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);

    loginBtn = text;
    rejestracjaBtn = text;
    sf::RectangleShape poleM1(sf::Vector2f(500, 70));
    poleM = poleM1;
    login = text;
    poleH = poleM;
    haslo = text;
    wyswietlMail = text;
    wyswietlHaslo = wyswietlMail;

    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    loginBtn.setString("Zaloguj sie");
    loginBtn.setCharacterSize(60);
    int loginBtnW = loginBtn.getLocalBounds().width;
    loginBtn.setPosition((width / 2 - loginBtnW / 2 - 200), 900);

    rejestracjaBtn.setString("Zarejestruj sie");
    rejestracjaBtn.setCharacterSize(60);
    int rejestracjaBtnW = rejestracjaBtn.getLocalBounds().width;

    rejestracjaBtn.setPosition((width / 2 - rejestracjaBtnW / 2 + 200), 900);

    CofnijBtn = Napis("Cofnij", 60, 2000, 1600);

    poleM.setPosition(width / 2 - 500 / 2, 500);
    poleM.setFillColor(sf::Color::White);
    
    login.setString("Email");
    login.setCharacterSize(50);
    int loginW = login.getLocalBounds().width;
    login.setPosition((width / 2 - loginW / 2), 420);

    poleH.setPosition(width / 2 - 500 / 2, 680);

    haslo.setString("Haslo");
    haslo.setCharacterSize(50);
    int hasloW = haslo.getLocalBounds().width;
    haslo.setPosition((width / 2 - loginW / 2), 600);

    wyswietlMail.setCharacterSize(45);
    wyswietlMail.setString("Wpisz e-mail");
    wyswietlMail.setFillColor(sf::Color::Black);
    wyswietlMail.setPosition(poleM.getPosition().x + 10, poleM.getPosition().y + 5);

    wyswietlHaslo = wyswietlMail;
    wyswietlHaslo.setPosition(poleH.getPosition().x + 10, poleH.getPosition().y + 5);
    wyswietlHaslo.setString("Wpisz haslo");
    alert = text;
    alert.setString("");
    alert.setCharacterSize(45);

    //register
    sf::RectangleShape pole(sf::Vector2f(500, 70));
    poleI = pole;
    poleI.setPosition(width / 2 - 500 / 2, 300);
    imieT = Pole("ffffff", poleI.getPosition().x, poleI.getPosition().y);

    poleN = pole;
    poleMR = pole;
    poleHR = pole;
    poleP = pole;
    poleA = pole;
    poleD = pole;

    poleN.setPosition(width / 2 - 500 / 2, 450);
    poleMR.setPosition(width / 2 - 500 / 2, 600);
    poleHR.setPosition(width / 2 - 500 / 2, 750);
    poleP.setPosition(width / 2 - 500 / 2, 900);
    poleA.setPosition(width / 2 - 500 / 2, 1050);
    poleD.setPosition(width / 2 - 500 / 2, 1200);

     nazwiskoT = Pole("", poleN.getPosition().x, poleN.getPosition().y);
     mailT = Pole("", poleMR.getPosition().x, poleMR.getPosition().y);
     hasloT = Pole("", poleHR.getPosition().x, poleHR.getPosition().y);
     peselT = Pole("", poleP.getPosition().x, poleP.getPosition().y);
     adresT = Pole("", poleA.getPosition().x, poleA.getPosition().y);
     nrdowodT = Pole("", poleD.getPosition().x, poleD.getPosition().y);


     boolid, boolmailNew = false;

     poleid = pole;
     poleid.setPosition(width / 2 - 500 / 2, 450);
     idT = Pole("", poleid.getPosition().x, poleid.getPosition().y);

     polemailNew = pole;
     polemailNew.setPosition(width / 2 - 500 / 2, 600);
     mailNewT = Pole("", polemailNew.getPosition().x, polemailNew.getPosition().y);



     for (int i = 0; i < 7; i++)
         statusPola.push_back(false);

     registerBtn = Napis("Zarejestruj sie", 60, width / 2 - 425 / 2, 1400);
     
     stareHaslo, noweHaslo = "";

     poleStareHaslo = pole;
     poleStareHaslo.setPosition(width / 2 - 500 / 2, 400);
     starehasloT = Pole("stare", poleStareHaslo.getPosition().x, poleStareHaslo.getPosition().y);

     poleNoweHalso = pole;
     poleNoweHalso.setPosition(width / 2 - 500 / 2, 550);
     nowehasloT = Pole("stare", poleNoweHalso.getPosition().x, poleNoweHalso.getPosition().y);

     //Transakcja


     for (int i = 0; i < 4; i++)
        statusPolTransakcja.push_back(false);

     poleKwota = pole;
     poleTytul = pole;
     poleOdbiorcy = pole;
     poleOkres = pole;

    
     poleKwota.setPosition(width / 2 - 500 / 2, 450);
     poleTytul.setPosition(width / 2 - 500 / 2, 600);
     poleOdbiorcy.setPosition(width / 2 - 500 / 2, 750);
     poleOkres.setPosition(width / 2 - 500 / 2, 750);

  
     kwotaT = Pole("Kwota", poleKwota.getPosition().x, poleKwota.getPosition().y);
     tytulT = Pole("Tytul", poleTytul.getPosition().x, poleTytul.getPosition().y);
     odbiorcaT = Pole("Odbiorca", poleOdbiorcy.getPosition().x, poleOdbiorcy.getPosition().y);
     okresT = Pole("Okres", poleOkres.getPosition().x, poleOkres.getPosition().y);


     IdOsoby = "";
     poleIdOsoby = pole;
     poleIdOsoby.setPosition(width / 2 - 500 / 2, 450);
     IdOsobyT = Pole("IdOsoby", poleIdOsoby.getPosition().x, poleIdOsoby.getPosition().y);
     IdOsobyB = false;
}
void Okno::ZaladujCzcionke()
{
    font.loadFromFile("arial.ttf");
    text.setFont(font);
}

sf::Text Okno::Napis(string tekst, int wielkosc, int x, int y)
{
    sf::Text text;
    text.setString(tekst);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setPosition(x, y);
    text.setCharacterSize(wielkosc);
    return text;

}

sf::Text Okno::Pole(string s,int x,int y)
{
    sf::Text wyswietl = text;
    wyswietl.setCharacterSize(45);
    wyswietl.setString(s);
    wyswietl.setFillColor(sf::Color::Black);
    wyswietl.setPosition(x + 10, y + 5);
    return wyswietl;
}
void Okno::Panel0(sf::RenderWindow& window,sf::Event event,Menu &menu,int &panel)
{
        bool nieudalo = false;
        bool badPole = false;

        Btn = Napis("Admin", 60, 1700, 900);
        window.draw(Btn);

    if (event.type == sf::Event::MouseMoved)          //czy myszka na login
       {
       sf::Vector2i mousePos = sf::Mouse::getPosition(window);
       sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
       if (loginBtn.getGlobalBounds().contains(mousePosF))
       {
          cout << "jest na login" << endl;
        }
                    
       }
        if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        if (loginBtn.getGlobalBounds().contains(mousePosF))
        {
            std::cout << "login klik" << std::endl;
            if (menu.GetStatus() == true)
            { 
                panel = 2;
                alert.setString("");
            }
            else
            {
                nieudalo = true;
                alert.setString("Nie udalo sie zalogowac, nieprawidlowe haslo badz email");
                alert.setPosition((width / 2 - alert.getLocalBounds().width / 2 - 200), 1100);
              
            }
           
         
        }
        if (rejestracjaBtn.getGlobalBounds().contains(mousePosF))
        {
            std::cout << "reestracja klik" << std::endl;
            panel = 1;
            
        }

       if (poleM.getGlobalBounds().contains(mousePosF))
        {
            boolMail = true;
            boolPassword = false;
        }

        if (poleH.getGlobalBounds().contains(mousePosF))
        {
            boolPassword = true;
            boolMail = false;
        }
       

        if (Btn.getGlobalBounds().contains(mousePosF))
        {
            if (menu.GoodPassword2(mail,password)&&menu.IsAdmin(mail))
                panel = 6;

            mail, password = "";
        }
        

           }
       


     if (menu.GoodPassword(mail, password))
    {
        menu.SetStatus(true);
        menu.logged=menu.GetSpecificKlient(mail);
    }

     window.draw(text);
     window.draw(loginBtn);
     window.draw(rejestracjaBtn);
     window.draw(poleM);
     window.draw(login);
     window.draw(poleH);
     window.draw(haslo);
     window.draw(wyswietlMail);
     window.draw(wyswietlHaslo);
         if (nieudalo==true)
    {
        window.draw(alert);
    }

      
}

void Okno::Panel1(sf::RenderWindow& window, sf::Event event, Menu &menu, int& panel)  // ulepszyc idosby generacja,i waidacja
{
    text.setString("Rejestracja");       //naglowek panel rejestracja
     title = text.getLocalBounds().width;
     text.setPosition((width / 2 - title / 2), 100);


     if (event.type == sf::Event::MouseButtonPressed)
     {
         sf::Vector2i mousePos = sf::Mouse::getPosition(window);
         sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
         if (registerBtn.getGlobalBounds().contains(mousePosF))
         {
             std::cout << "register klik" << std::endl;

             if (imie != "" && nazwisko != "" && mailR != "" && hasloR != "" && pesel != "" && adres != "" && dowod != "")
             {

                 if (menu.Email_check(mailR) == false )
                 {
                    alert.setString("Zla forma email");
                     alert.setPosition(width / 2 - 500 / 2+600, 600);

                 }
                
             }


             if (menu.GetStatus() == true)
             {
                 panel = 2;
                 alert.setString("");

             }

             if (menu.MailAvailable(mailR) == true && menu.Email_check(mailR) == true)
             {
                 
                 menu.klienci.push_back(Osoba(menu.OstatnieID()+1, imie, nazwisko, mailR, hasloR, pesel, adres, dowod));
                 /* Osoba o(menu.lastUserId,imie,nazwisko,mailR,hasloR,pesel,adres,dowod);*/
                  //menu.logged = Osoba(menu.lastUserId, imie, nazwisko, mailR, hasloR, pesel, adres, dowod);
                 menu.logged = menu.GetSpecificKlient(mailR);
                // menu.Setlogged(menu.GetSpecificKlient(mailR));
                 
                 menu.status = true;
                 imie, nazwisko, mailR, hasloR, pesel, adres, dowod = "";
                 imieT.setString("");
                 nazwiskoT.setString("");
                 mailT.setString("");
                 hasloT.setString("");
                 peselT.setString("");
                 adresT.setString("");
                 nrdowodT.setString("");

             }
         }
        
        
        
         if (CofnijBtn.getGlobalBounds().contains(mousePosF))
         {
             panel = 0;
             imie, nazwisko, mailR, hasloR, pesel, adres, dowod = "";
             imieT.setString(""); 
             nazwiskoT.setString("");
             mailT.setString("");
             hasloT.setString("");
             peselT.setString("");
             adresT.setString("");
             nrdowodT.setString("");
             alert.setString("");
         }
     }

     window.draw(Napis("Imie: ", 60, width / 2 - 400, 300));
     window.draw(Napis("Nazwisko: ", 60, width / 2 - 550, 450));
     window.draw(Napis("Mail: ", 60, width / 2 - 400, 600));
     window.draw(Napis("Haslo: ", 60, width / 2 - 440, 750));
     window.draw(Napis("Pesel: ", 60, width / 2 - 440, 900));
     window.draw(Napis("Adres: ", 60, width / 2 - 440, 1050));
     window.draw(Napis("Nr Dowod: ", 60, width / 2 - 550, 1200));
     window.draw(text);
     window.draw(CofnijBtn);

     window.draw(poleI);
     window.draw(poleN);
     window.draw(poleMR);
     window.draw(poleHR);
     window.draw(poleP);
     window.draw(poleA);
     window.draw(poleD);
     window.draw(registerBtn);
     window.draw(imieT);
     window.draw(nazwiskoT);
     window.draw(mailT);
     window.draw(hasloT);
     window.draw(peselT);
     window.draw(adresT);
     window.draw(nrdowodT);
     window.draw(alert);

}

void Okno::Panel2(sf::RenderWindow& window, sf::Event event, Menu &menu, int& panel)
{
    
    
    menu.GetBaza();
    bool NewKonto = false;
    alert.setPosition(1900, 300);
    window.draw(alert);
    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        if (KontoBtnObszar1.contains(mousePosF))
        {
            std::cout << "Konto klik" << std::endl;
            UstawKonto = menu.IleKont(menu.logged)[0];
            panel = 4;

        }
        if (KontoBtnObszar2.contains(mousePosF))
        {
            std::cout << "Konto klik" << std::endl;
            UstawKonto = menu.IleKont(menu.logged)[1];
            panel = 4;
        }
        if (KontoBtnObszar3.contains(mousePosF))
        {
            std::cout << "Konto klik" << std::endl;
            UstawKonto = menu.IleKont(menu.logged)[2];
            panel = 4;
        }

        if (Btn2.getGlobalBounds().contains(mousePosF))
        {
            if (SaldoNieUjemne(menu.IleKont(menu.logged)[0]))
                menu.DeleteKonto(menu.IleKont(menu.logged)[0]);
            else
                alert.setString("Ujemne konto!!!");
        }
        if (Btn3.getGlobalBounds().contains(mousePosF))
        {
            if (SaldoNieUjemne(menu.IleKont(menu.logged)[1]))
            menu.DeleteKonto(menu.IleKont(menu.logged)[1]);
            else
                alert.setString("Ujemne konto!!!");
        }

        if (Btn4.getGlobalBounds().contains(mousePosF))
        {
            if (SaldoNieUjemne(menu.IleKont(menu.logged)[2]))
            menu.DeleteKonto(menu.IleKont(menu.logged)[2]);
            else
                alert.setString("Ujemne konto!!!");
        }

        if (NoweKontoBtn.getGlobalBounds().contains(mousePosF))
        {
            std::cout << "Utworz nowe konto Indywidualne klik" << std::endl;

            if (menu.IleKont(menu.logged).size() >= 3)
            {
                alert.setString("Maksymalna liczba 3 kont osiagnieta!!!");
                alert.setPosition(1280, 750);
                alert.setCharacterSize(60);
                NewKonto = true;

            }
            else
            {
                menu.CreateNewKonto("I");


            }



        }
        if (NoweKontoBtn2.getGlobalBounds().contains(mousePosF))
        {
            std::cout << "Utworz nowe konto firmowe klik" << std::endl;

            if (menu.IleKont(menu.logged).size() >= 3)
            {
                alert.setString("Maksymalna liczba 3 kont osiagnieta!!!");
                alert.setPosition(1280, 750);
                alert.setCharacterSize(60);
                NewKonto = true;
            }
            else
            {
                menu.CreateNewKonto("F");


            }

        }
        if(NewKonto == true)
        window.draw(alert);

        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 0;

            menu.SetStatus(false);
            Osoba o;
            menu.logged = o;
            mail = "";
            password = "";
            alert.setString("");
            wyswietlHaslo.setString("Wpisz haslo");
            wyswietlMail.setString("Wpisz E-mail");
        }
      
        if (ZmienHaslo.getGlobalBounds().contains(mousePosF))
        {
            panel = 5;
        }

       
     }
    }

void Okno::PanelKontaBankowego4(sf::RenderWindow& window, sf::Event event, Konto k, Menu &menu,int& panel)
{
    menu.GetBaza();
    menu.WybraneKonto = k;
    window.clear(sf::Color(230, 165, 190));
    sf::Text KontoB = Napis("Konto bankowe", 100, 10, 10);
    KontoB.setPosition(width / 2 - KontoB.getLocalBounds().width, 100);

  

    window.draw(KontoB);
    window.draw(Napis(k.GiveKontoInString(), 50, 150, 300));

    if (event.type == sf::Event::Closed)    //zamka okno
    {
        window.close();
    }

    sf::Text PrzelewBtn=Napis("Zrob przelew",70,100,500);
    sf::Text WyplataWplataBtn= Napis("Zrob wyplata/wplata", 70,700, 500);
    sf::Text KredytBtn= Napis("Wez kredyt", 70, 1500, 500);

    window.draw(PrzelewBtn);
    window.draw(WyplataWplataBtn);
    window.draw(KredytBtn);
    window.draw(CofnijBtn);

    vector<Transakcja*> transaction = menu.TransakcjeDlaKonta(k);
    transaction = Sortowanie(transaction);
    reverse(transaction.begin(), transaction.end());
    window.draw(Napis("Historia", 60, 150, 700));

    int ile = 0;
    for (auto i : transaction)
    {
        window.draw(Napis(i->Show(), 50, 50, 800+ile*70));
        ile++;
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        if (PrzelewBtn.getGlobalBounds().contains(mousePosF))
        {
            std::cout << "przelew klik" << std::endl;
            Przelew* p = new Przelew;
            menu.operacja=p;
            menu.operacja->SetTyp("przelew");
            panel = 3;

        }

        if (WyplataWplataBtn.getGlobalBounds().contains(mousePosF))
        {
            std::cout << "wyplata klik" << std::endl;
            Wyplata* w = new Wyplata;
            menu.operacja=w;

            panel = 3;
        }

        if (KredytBtn.getGlobalBounds().contains(mousePosF))
        {
            if (SaldoNieUjemne(k))
            {
                std::cout << "kredyt klik" << std::endl;
                Kredyt* k = new Kredyt;
                menu.operacja = k;
                menu.operacja->SetTyp("kredyt");
                panel = 3;
                alert.setString("");

            }
            else
            {
                alert.setString("Ujemne saldo");
                window.draw(alert);
            }

        }

        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 2;
            alert.setString("");
        }
    }
}
void Okno::Zalogowany(sf::RenderWindow& window,Menu menu)
{
    text.setString("Zalogowany");       //naglowek panel zalogowany
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);

    //----Rysowanie---
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(Napis("Dane klienta:", 60, 150, 360));
    sf::Text imie = Napis(menu.logged.GetImie(), 50, 150, 440);
    window.draw(imie);
    window.draw(Napis(menu.logged.GetNazwisko(), 50, 150 + imie.getLocalBounds().width + 20, 440));
    window.draw(Napis(menu.logged.GetAdres(), 50, 150, 510));
    sf::Text pesel = Napis("Pesel: " + menu.logged.GetPesel(), 50, 150, 590);
    window.draw(pesel);

    window.draw(Napis("Dowod: " + menu.logged.GetNrDowodu(), 50, 150 + pesel.getLocalBounds().width + 20, 590));

    sf::Text mail = Napis("Mail: " + menu.logged.GetMail(), 50, 150, 670);
    window.draw(mail);
    window.draw(Napis("Haslo: " + menu.logged.GetHaslo(), 50, 150 + mail.getLocalBounds().width + 20, 670));

    window.draw(Napis("Konta", 60, 250, 1100));

    

   

   

    NoweKontoBtn = text;
    NoweKontoBtn.setCharacterSize(60);
    NoweKontoBtn.setString("Utworz nowe konto indywidualne");
    NoweKontoBtn.setPosition(700, 1100);
    window.draw(NoweKontoBtn);

    window.draw(CofnijBtn);
    ZmienHaslo = Napis("Zmien haslo", 60, 1900, 400);
    window.draw(ZmienHaslo);

    NoweKontoBtn2 = Napis("Utworz konto firmowe", 60, NoweKontoBtn.getLocalBounds().width + 800, 1100);


    int i = 0;
    for (auto k : menu.IleKont(menu.logged))
    {
        

        sf::Text KontoBtn(text);            //przycisk konto
    KontoBtn.setString("Konto "+to_string(i+1)+":");
    KontoBtn.setCharacterSize(50);
 
    KontoBtn.setPosition(150, 1230+i * 70);

   

    if (i == 0)

    {
        KontoBtnObszar1 = KontoBtn.getGlobalBounds();

        Btn2 = Napis("Usun konto 1", 60, 1900, 500);
        window.draw(Btn2);
    }
    if (i == 1)
    {
        KontoBtnObszar2 = KontoBtn.getGlobalBounds();

        Btn3 = Napis("Usun konto 2", 60, 1900, 600);
        window.draw(Btn3);
    }
    if (i == 2)
    {
        KontoBtnObszar3 = KontoBtn.getGlobalBounds();
        Btn4 = Napis("Usun konto 3", 60, 1900, 700);
        window.draw(Btn4);

    }

    window.draw(KontoBtn);
    

        window.draw(Napis(k.GiveKontoInString(), 50, 350, 1230+i*70));
        i++;
        if (i >= 3)
            break;
    }
    window.draw(NoweKontoBtn2);
}

void Okno::Panel3Transakcja(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    window.clear(sf::Color(230, 165, 190));
    text.setString(menu.operacja->Nazwa());       //naglowek panel rejestracja
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);

    Btn = Napis("Wykonaj", 60, 1100, 1100);
    WyplataBtn = Napis("Wyplata", 60, 900, 1100);
    WplataBtn = Napis("Wplata", 60, 1200, 1100);

    if (event.type == sf::Event::Closed)    //zamka okno
    {
        window.close();
    }
    if (menu.operacja->Nazwa() == "Wyplata/Wplata")
    {
        window.draw(WyplataBtn);
        window.draw(WplataBtn);
    }


    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
       
        if (menu.operacja->Nazwa() == "Wyplata/Wplata")
        {
            if (WplataBtn.getGlobalBounds().contains(mousePosF))
            {

                if (menu.operacja->Nazwa() == "Wyplata/Wplata" && CzyLiczba(kwota) && CzyTekst(tytul))
                {

                    stringstream ss(to_string(menu.WybraneKonto.GetNrKonta()) + " " + GetDataNow() + " " + kwota + " " + tytul + " " + "wplata/wyplata");
                    Wyplata* w = new Wyplata;
                    ss >> *w;
                    menu.transakcje.push_back(w);
                    cout << "udalo sie";

                    menu.AktualizujSaldo(stoi(kwota));
                    menu.GetBaza();
                    ZerujTransakcje();
                }
            }

            if (WyplataBtn.getGlobalBounds().contains(mousePosF))
            {

                if (menu.operacja->Nazwa() == "Wyplata/Wplata" && CzyLiczba(kwota) && CzyTekst(tytul))
                {

                    stringstream ss(to_string(menu.WybraneKonto.GetNrKonta()) + " " + GetDataNow() + " -" + kwota + " " + tytul + " " + "wplata/wyplata");
                    Wyplata* w = new Wyplata;
                    ss >> *w;
                    menu.transakcje.push_back(w);
                    cout << "udalo sie";

                    menu.AktualizujSaldo(-stoi(kwota));
                    menu.GetBaza();
                    ZerujTransakcje();
                }
            }
            menu.GetBaza();
        }
        if (menu.operacja->Nazwa() != "Wyplata/Wplata")
        {
            if (Btn.getGlobalBounds().contains(mousePosF))
            {



                if (menu.operacja->Nazwa() == "Przelew" && CzyLiczba(kwota) && CzyTekst(tytul) && CzyLiczba(nr_odbiorcy))
                {

                    stringstream ss(to_string(menu.WybraneKonto.GetNrKonta()) + " " + nr_odbiorcy + " " + GetDataNow() + " " + kwota + " " + tytul + " " + "przelew");
                    Przelew* p = new Przelew;
                    ss >> *p;
                    menu.transakcje.push_back(p);
                    menu.AktualizujDlaKontaPrzelew(stoi(nr_odbiorcy), stoi(kwota));
                    cout << "udalo sie";
                    ZerujTransakcje();
                }
                if (menu.operacja->Nazwa() == "Kredyt" && CzyLiczba(kwota) && CzyTekst(tytul) && CzyLiczba(okres))
                {


                    stringstream ss(to_string(menu.WybraneKonto.GetNrKonta()) + " " + GetDataNow() + " " + okres + " " + kwota + " " + to_string(Rata(kwota, okres)) + " " + tytul + " " + "kredyt");
                    Kredyt* k = new Kredyt;
                    ss >> *k;
                    menu.transakcje.push_back(k);
                    menu.AktualizujSaldo(stoi(kwota));
                    cout << "udalo sie";
                }
                menu.GetBaza();
            }
        }

        if (poleKwota.getGlobalBounds().contains(mousePosF))
        {
            statusPolTransakcja[0] = true;
            statusPolTransakcja[1] = false;
           statusPolTransakcja[2] = false;
            statusPolTransakcja[3] = false;
        }

        if (poleTytul.getGlobalBounds().contains(mousePosF))
        {
            statusPolTransakcja[0] = false;
            statusPolTransakcja[1] = true;
            statusPolTransakcja[2] = false;
            statusPolTransakcja[3] = false;
        }

        if (menu.operacja->Nazwa() == "Przelew")
        {

            if (poleOdbiorcy.getGlobalBounds().contains(mousePosF))
            {
                statusPolTransakcja[0] = false;
                statusPolTransakcja[1] = false;
                statusPolTransakcja[2] = true;
                statusPolTransakcja[3] = false;
            }
        }

        if (menu.operacja->Nazwa() == "Kredyt")
        {

            if (poleOdbiorcy.getGlobalBounds().contains(mousePosF))
            {
                statusPolTransakcja[0] = false;
                statusPolTransakcja[1] = false;
                statusPolTransakcja[2] = false;
                statusPolTransakcja[3] = true;
            }
        }

        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 4;
            alert.setString("");
            menu.GetBaza();
        }
    }

     
    window.draw(CofnijBtn);
    window.draw(text);
    window.draw(alert);
    if (menu.operacja->Nazwa() != "Wyplata/Wplata")
    {
        window.draw(Btn);

    }
    window.draw(Napis("Kwota: ", 60, width / 2 - 440, 450));
    window.draw(Napis("Tytul: ", 60, width / 2 - 400, 600));
    if (menu.operacja->Nazwa() == "Przelew")
    window.draw(Napis("Nr Odbiorcy: ", 60, width / 2 - 600, 750));
    if (menu.operacja->Nazwa() == "Kredyt")
    window.draw(Napis("Okres: ", 60, width / 2 - 440, 750));

    window.draw(poleKwota);
    window.draw(poleTytul);
    window.draw(kwotaT);
    window.draw(tytulT);
    if (menu.operacja->Nazwa() == "Przelew")
    {
        window.draw(poleOdbiorcy);
        window.draw(odbiorcaT);
    }
    if (menu.operacja->Nazwa() == "Kredyt")
    {
        window.draw(poleOkres);
        window.draw(okresT);
    }
}


void Okno::ZerujTransakcje()
{
    kwota,nr_odbiorcy,okres, tytul = "";
    for (int i = 0; i < 4; i++)
        statusPolTransakcja.push_back(false);

}

void Okno::Panel5ZmianaHasla(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    text.setString("Zmiana Hasla");       //naglowek panel rejestracja
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);

    if (event.type == sf::Event::Closed)    //zamka okno
    {
        window.close();
    }

    Btn = Napis("Zmien", 60, 1100, 700);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
   
    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        if (Btn.getGlobalBounds().contains(mousePosF))
        {
            if (menu.GoodPassword(mail, stareHaslo) && noweHaslo != "")
            {
                menu.logged.SetHaslo(noweHaslo);
                menu.ChangePassword(noweHaslo);
            }
            else
            {
                alert.setString("Zle haslo wpisane");
                alert.setPosition(400, 700);
            }
                cout << "zmiana" << endl;
        }
        if (poleStareHaslo.getGlobalBounds().contains(mousePosF))
        {
            boolstareHaslo = true;
            boolnoweHaslo = false;
        }

        if (poleNoweHalso.getGlobalBounds().contains(mousePosF))
        {
            boolstareHaslo = false;
            boolnoweHaslo = true;
        }
        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 2;
            alert.setString("");
            
        }
    }
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(alert);
    window.draw(CofnijBtn);
    window.draw(poleStareHaslo);
   
    window.draw(poleNoweHalso);
   
    window.draw(starehasloT);
    window.draw(nowehasloT);
    window.draw(Btn);
    window.draw(Napis("Stare: ", 60, width / 2 - 440, 400));
    window.draw(Napis("Nowe: ", 60, width / 2 - 440, 550));
}

    
void Okno::Panel6Admin(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    text.setString("Widok Administracyjny");       //naglowek panel rejestracja
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(Napis("Lista Klientow", 50, 70, 250));
    

    Btn = Napis("Usun uzytkownika", 50, 1800, 500);
    Btn2 = Napis("Znajdz konto", 50, 1800, 650);
    Btn3 = Napis("Modyfikuj uzytkownika", 50, 1800, 800);
    Btn4 = Napis("Klienci wszyscy", 50, 1800, 950);
    window.draw(Btn);
    window.draw(Btn2);
    window.draw(Btn3);
    window.draw(CofnijBtn);
    window.draw(Btn4);
    window.draw(Napis("Lista Kont", 50, 70, 850));
  int ile = 0;
    for (auto i : menu.klienci | views::take(8))
    {
        window.draw(Napis(i.Show(), 45, 50, 400 + ile * 70));
        ile++;
    }
    ile = 0;
    for (auto i : menu.konta | views::take(8))
    {
        window.draw(Napis(i.Show(), 45, 50, 1000 + ile * 70));
        ile++;
    }
   
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        if (Btn.getGlobalBounds().contains(mousePosF))
        {
            panel = 7;
            IdOsoby = "";
            IdOsobyT.setString("IdOsoby");
        }

        if (Btn2.getGlobalBounds().contains(mousePosF))
        {
            panel = 8;
            IdOsoby = "";
            IdOsobyT.setString("Nr konta");
        }
        if (Btn3.getGlobalBounds().contains(mousePosF))
        {
            panel = 10;
            IdOsoby = "";
            IdOsobyT.setString("Nr konta");
        }
        if (Btn4.getGlobalBounds().contains(mousePosF))
        {
            panel = 11;
            IdOsoby = "";
            IdOsobyT.setString("Nr konta");
        }


        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 0;
            alert.setString("");
            wyswietlMail.setString("Wpisz email");
            wyswietlHaslo.setString("Wpisz haslo");
            mail = "";
            password = "";
        }

        if (poleIdOsoby.getGlobalBounds().contains(mousePosF))
        {
            IdOsobyB = true;
        }
    }


}
void Okno::Panel7UsunUzytkownika(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    text.setString("Usun uzytkownika");      
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(Napis("IdOsoby do usuniecia:", 50, width / 2 - 750, 450));
    window.draw(poleIdOsoby);
    window.draw(IdOsobyT);
    window.draw(CofnijBtn);

    Btn = Napis("Wykonaj", 60, width / 2 - 100, 600);
    window.draw(Btn);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        if (Btn.getGlobalBounds().contains(mousePosF))
        {
            if (IdOsoby != "" && CzyLiczba(IdOsoby) && menu.CzyJestTakieId(IdOsoby))
            {
                menu.DeleteAccount(IdOsoby);
                cout << "okej";
            }
        }

        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 6;
            IdOsoby = "";
            IdOsobyT.setString("IdOsoby");
        }

        if (poleIdOsoby.getGlobalBounds().contains(mousePosF))
        {
            IdOsobyB = true;
        }
    }


}

void Okno::Panel8ZnajdzKonto(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    text.setString("Znajdz Konto");
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(Napis("Numer konta:", 50, width / 2 - 650, 450));
    window.draw(poleIdOsoby);
    window.draw(IdOsobyT);
    window.draw(CofnijBtn);

    Btn = Napis("Wykonaj", 60, width / 2 - 100, 600);
    window.draw(Btn);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        if (Btn.getGlobalBounds().contains(mousePosF))
        {
            if (IdOsoby != "" && CzyLiczba(IdOsoby) && menu.IsKonto(IdOsoby))
            {
                panel = 9;
                cout << "okej";
            }
        }

        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 6;
            IdOsoby = "";
            IdOsobyT.setString("");
        }

        if (poleIdOsoby.getGlobalBounds().contains(mousePosF))
        {
            IdOsobyB = true;
        }
    }
}

void Okno::Panel9KontozTrans(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    text.setString(" Konto");
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(Napis("Konto:", 50, 150, 200));
 

    window.draw(CofnijBtn);
    Konto k = menu.KontoDlaNr(IdOsoby);
    window.draw(Napis(to_string(k.GetIdOsoby()) + " " + k.GetImie() + " " + k.GetNazwisko(), 50, 150, 270));
    window.draw(Napis(k.GiveKontoInString(), 50, 150, 350));

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    vector<Transakcja*> transaction = menu.TransakcjeDlaKonta(k);
    transaction = Sortowanie(transaction);
    reverse(transaction.begin(), transaction.end());
    window.draw(Napis("Historia", 60, 150, 700));

    int ile = 0;
    for (auto i : transaction|views::take(10))
    {
        window.draw(Napis(i->Show(), 50, 50, 800 + ile * 70));
        ile++;
    }


    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {
        




        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 8;
            IdOsoby = "";
            IdOsobyT.setString("");
        }

       
    }

}

void Okno::Panel10Modyfikuj(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel)
{
    text.setString(" Modyfikuj");
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    window.draw(poleid);
    window.draw(polemailNew);
    window.draw(idT);
    window.draw(mailNewT);

    window.draw(Napis("ID", 60, width/2-350, 450));
    window.draw(Napis("Mail nowy", 60, width/2-600, 600));
    Btn = Napis("Wykonaj", 60, width / 2 - 100, 750);
    window.draw(Btn);


    window.draw(CofnijBtn);



    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


      if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {

          if (Btn.getGlobalBounds().contains(mousePosF))
          {
              if (id != "" && mailNew!=""&&CzyLiczba(id) && menu.CzyJestTakieId(id))
              {
                  
                  if (menu.MailAvailable(mailNew) == true && menu.Email_check(mailNew) == true)
                  {
                      menu.ModifyMail(mailNew, id);
                      id, mailNew = "";

                      
                  }
              }
          }

        if (poleid.getGlobalBounds().contains(mousePosF))
        {
            boolid = true;
            boolmailNew = false;
        }

        if (polemailNew.getGlobalBounds().contains(mousePosF))
        {
            boolid = false;
            boolmailNew = true;
        }
        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 6;
            id, mailNew = "";
            idT.setString("");
            mailNewT.setString("");
          
        }


    }    
   
}

void Okno::Panel11OsobyZKontem(sf::RenderWindow& window, sf::Event event, Menu menu, int& panel)
{
    if (event.type == sf::Event::Closed)    //zamka okno
    {
        window.close();
    }

    text.setString(" Klienci wszyscy");
    title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);
    window.clear(sf::Color(230, 165, 190));
    window.draw(text);
    int ile = 0;
    for (auto i : menu.klienci | views::reverse | views::all)
    {
        window.draw(Napis(i.Show(), 45, 50, 300 + ile*70));
        ile++;
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
    {

        if (CofnijBtn.getGlobalBounds().contains(mousePosF))
        {
            panel = 6;

        }

    }

    window.draw(CofnijBtn);

}