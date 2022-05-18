#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "klasy.h"
#include "textbox.h"

using namespace std;

int width = 2400, height = 1800;
sf::RenderWindow window(sf::VideoMode(width, height), "System bankowy");
sf::Text text;
sf::Font font;
Konto user;
Menu menu;


int main()
{
    Osoba o("ala", "ala1", "ala2", "ala4", "ala5", "ala6", "ala7");
    Konto k(2324411,34.40,'I',o);
    //k.SetImie("bob");
    cout << k.GetImie()<<endl;
    double ile = 23.89;
    k.ChangeSaldo(k.GetSaldo() - ile);
    cout << k.GetSaldo() << endl;
   

    sf::String s("System bankowy");             //naglowek panel logowania
    text.setString(s);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(100);
  /*  if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "nie zaladowal czcionki";
    }*/
    
   

    font.loadFromFile("arial.ttf");
    text.setFont(font);

    int title = text.getLocalBounds().width;
    text.setPosition((width / 2 - title / 2), 100);

    sf::Text loginBtn(text);                               //przycisk login
    loginBtn.setString("Zaloguj sie");
    loginBtn.setCharacterSize(60);
    int loginBtnW = loginBtn.getLocalBounds().width;
    int loginBtnH = loginBtn.getLocalBounds().height;
    loginBtn.setPosition((width / 2 - loginBtnW / 2-200), 900);

    sf::Text rejestracjaBtn(text);                           //przycisk rejestracji
    rejestracjaBtn.setString("Zarejestruj sie");
    rejestracjaBtn.setCharacterSize(60);
    int rejestracjaBtnW = rejestracjaBtn.getLocalBounds().width;
    int rejestracjaBtnH = rejestracjaBtn.getLocalBounds().height;
    rejestracjaBtn.setPosition((width / 2 - rejestracjaBtnW / 2+200), 900);

    sf::RectangleShape poleM(sf::Vector2f(500, 70));        //pole do wpisywania mail
    poleM.setPosition(width / 2 - 500 / 2, 500);
    poleM.setFillColor(sf::Color::White);

    sf::Text login(text);                               //napis email
    login.setString("Email");
    login.setCharacterSize(50);
    int loginW = login.getLocalBounds().width;
    login.setPosition((width / 2 - loginW / 2), 420);



    sf::RectangleShape poleH(poleM);        //pole do wpisywania haslo
    poleH.setPosition(width / 2 - 500 / 2, 680);
  


    sf::Text haslo(text);                           //napis haslo
    haslo.setString("Haslo");
    haslo.setCharacterSize(50);
    int hasloW = haslo.getLocalBounds().width;
    haslo.setPosition((width / 2 - loginW / 2), 600);

    sf::Text wyswietlMail(text);                    //wyswietlony wpisany mail
    wyswietlMail.setCharacterSize(45);
    wyswietlMail.setString("qwok2312313");
    wyswietlMail.setFillColor(sf::Color::Black);
    wyswietlMail.setPosition(poleM.getPosition().x + 10, poleM.getPosition().y + 5);

    sf::Text wyswietlHaslo(wyswietlMail);           //wyswietlone wpisane haslo
    wyswietlHaslo.setPosition(poleH.getPosition().x + 10, poleH.getPosition().y + 5);
   
    //-----------Panel rejestracji-------------------
    sf::RectangleShape poleIandN(poleM);        //pole do wpisywania imienia
    sf::Text IandN(login);
    IandN.setString("Imie i nazwisko");
    

    sf::RectangleShape poleTele(poleM);        //pole do wpisywania imienia
    sf::Text Tele(login);
    Tele.setString("Telefon");

    int panel = 0;
    //---------------ZROBIC POZYCJE WEWNATRZ PANELI----------------------------------
    string displayName;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {       
            if (panel == 0)
            {
                if (event.type == sf::Event::Closed)     //zamyka onko 
                {
                    window.close();
                }
                if (event.type == sf::Event::MouseMoved)          //czy myszka na login
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (loginBtn.getGlobalBounds().contains(mousePosF))
                    {
                        cout << "jest na login" << endl;
                    }
                    else
                    {
                        cout << "nie jest" << endl;
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (loginBtn.getGlobalBounds().contains(mousePosF))
                    {
                        std::cout << "login klik" << std::endl;
                        panel = 2;
                        continue;
                      

                    }
                    if (rejestracjaBtn.getGlobalBounds().contains(mousePosF))
                    {
                        std::cout << "reestracja klik" << std::endl;
                        panel = 1;
                        continue;


                    }

                    if (poleM.getGlobalBounds().contains(mousePosF))
                    {

                        cin >> displayName;
                        wyswietlMail.setString(displayName);


                    }

                    if (poleH.getGlobalBounds().contains(mousePosF))
                    {

                        cin >> displayName;
                        wyswietlHaslo.setString(displayName);
                    }

                }





                //----Rysowanie---
                window.clear(sf::Color(230, 165, 190));
                window.draw(text);
                window.draw(loginBtn);
                window.draw(rejestracjaBtn);
                window.draw(poleM);
                window.draw(login);
                window.draw(poleH);
                window.draw(haslo);
                window.draw(wyswietlMail);
                window.draw(wyswietlHaslo);

            }
            
            if (panel == 1)
            {
                if (event.type == sf::Event::Closed)        //zamyka onko 
                {
                    window.close();
                }


                string imie, mailS, hasloS, telefon;

                //------Ustawianie----------
                text.setString("Rejestracja");       //naglowek panel rejestracja
                title = text.getLocalBounds().width;
                text.setPosition((width / 2 - title / 2), 100);
                IandN.setPosition(width / 2 - IandN.getLocalBounds().width / 2, 320);
                login.setPosition(width / 2 - login.getLocalBounds().width / 2, 500);
                Tele.setPosition(width / 2 - Tele.getLocalBounds().width / 2, 680);
                haslo.setPosition(width / 2 - haslo.getLocalBounds().width / 2, 860);

                poleIandN.setPosition(width / 2 - 500 / 2, 400);
                poleM.setPosition(width / 2 - 500 / 2, 580);
                poleTele.setPosition(width / 2 - 500 / 2, 760);
                poleH.setPosition(width / 2 - 500 / 2, 940);
                rejestracjaBtn.setPosition((width / 2 - rejestracjaBtnW / 2 ), 1100);

                //---------mechanika----------

                if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (rejestracjaBtn.getGlobalBounds().contains(mousePosF))
                    {
                        std::cout << "rejestracja klik" << std::endl;
                        panel = 2;
                        continue;


                    }

      

                    if (poleIandN.getGlobalBounds().contains(mousePosF))
                    {

                        cin >> imie;
                        wyswietlMail.setString(imie);


                    }
                    if (poleTele.getGlobalBounds().contains(mousePosF))
                    {

                        cin >> telefon;
                        wyswietlMail.setString(telefon);


                    }

                    if (poleM.getGlobalBounds().contains(mousePosF))
                    {

                        cin >> mailS;
                        wyswietlMail.setString(mailS);


                    }

                    if (poleH.getGlobalBounds().contains(mousePosF))
                    {

                        cin >> hasloS;
                        wyswietlHaslo.setString(hasloS);
                    }

                    
                }

                //----Rysowanie---
                window.clear(sf::Color(230, 165, 190));
                window.draw(poleIandN);
                window.draw(poleTele);
                window.draw(poleM);
                window.draw(poleH);
                window.draw(IandN);
                window.draw(login);
                window.draw(Tele);
                window.draw(haslo);
                window.draw(text);
                window.draw(rejestracjaBtn);


            }

            if (panel == 2)
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }
                //------Ustawianie----------
                text.setString("Zalogowany");       //naglowek panel zalogowany
                title = text.getLocalBounds().width;
                text.setPosition((width / 2 - title / 2), 100);


                //----Rysowanie---
                window.clear(sf::Color(230, 165, 190));
                window.draw(text);



            }
                window.display();
            }

       
        
    }
    

    return 0;
}