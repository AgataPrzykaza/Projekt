#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include<sstream>
//#include "source.h"
#include "klasy.h"

#include "SFML.h"
//import Pracownik;


using namespace std;




Okno widok;
sf::RenderWindow window(sf::VideoMode(widok.width,widok.height), "System bankowy");

Konto user;
Menu menu;


int main()
{
    menu.GetPracownicy();
    for (auto i : menu.pracownicy)
    {
        cout << i<<endl;
    }
   
  

    menu.GetKlienci();
   //// menu.SaveKlienci();
    menu.GetKonta();
   //// menu.SaveKonta();

    menu.GetTransakcje();
    menu.GetKredyty();
    menu.GetBaza();
    
    menu.KredytyOdswiezone();

   cout << endl;
  
    widok.ZaladujCzcionke();

   widok.SetTexts();

    int panel = 0;
    //---------------ZROBIC POZYCJE WEWNATRZ PANELI----------------------------------
    string displayName;

   // sf::RectangleShape pole(sf::Vector2f(500, 70));
   //// sf::RectangleShape poleI = pole;
   // sf::RectangleShape poleN = pole;
   // sf::RectangleShape poleM = pole;
   // sf::RectangleShape poleH = pole;
   // sf::RectangleShape poleP = pole;
   // sf::RectangleShape poleA = pole;
   // sf::RectangleShape poleD = pole;

   // //poleI.setPosition(widok.width / 2 - 500 / 2, 300);
   // poleN.setPosition(widok.width / 2 - 500 / 2, 450);
   // poleM.setPosition(widok.width / 2 - 500 / 2, 600);
   // poleH.setPosition(widok.width / 2 - 500 / 2, 750);
   // poleP.setPosition(widok.width / 2 - 500 / 2, 900);
   // poleA.setPosition(widok.width / 2 - 500 / 2, 1050);
   // poleD.setPosition(widok.width / 2 - 500 / 2, 1200);

   // //sf::Text imieT = widok.Pole("ffffff", poleI.getPosition().x, poleI.getPosition().y);
   // sf::Text nazwiskoT = widok.Pole("ffffff", poleN.getPosition().x, poleN.getPosition().y);
   // sf::Text mailT = widok.Pole("ffffff", poleM.getPosition().x, poleM.getPosition().y);
   // sf::Text hasloT = widok.Pole("ffffff", poleH.getPosition().x, poleH.getPosition().y);
   // sf::Text peselT = widok.Pole("ffffff", poleP.getPosition().x, poleP.getPosition().y);
   // sf::Text adresT = widok.Pole("ffffff", poleA.getPosition().x, poleA.getPosition().y);
   // sf::Text nrdowodT = widok.Pole("ffffff", poleD.getPosition().x, poleD.getPosition().y);
   /* vector<bool> statusPola;
    string imie, nazwisko, mail, haslo, pesel, adres, dowod;*/

    menu.showT();
   
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {       
            if (panel == 0)
            {
            //    bool nieudalo = false;
            //    bool badPole = false;
            //    if (event.type == sf::Event::Closed)     //zamyka onko 
            //    {
            //        window.close();
            //    }
            //    if (event.type == sf::Event::MouseMoved)          //czy myszka na login
            //    {
            //        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            //        if (loginBtn.getGlobalBounds().contains(mousePosF))
            //        {
            //            cout << "jest na login" << endl;
            //        }
            //        
            //   }
            //    if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
            //    {
            //        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            //        if (loginBtn.getGlobalBounds().contains(mousePosF))
            //        {
            //            std::cout << "login klik" << std::endl;
            //            if (menu.GetStatus() == true)
            //            { 
            //                panel = 2;
            //                continue;
            //            }
            //            else
            //            {
            //                nieudalo = true;
            //                alert.setString("Nie udalo sie zalogowac, nieprawidlowe haslo badz email");
            //                alert.setPosition((width / 2 - alert.getLocalBounds().width / 2 - 200), 1100);
            //              
            //            }
            //           
            //         
            //        }
            //        if (rejestracjaBtn.getGlobalBounds().contains(mousePosF))
            //        {
            //            std::cout << "reestracja klik" << std::endl;
            //            panel = 1;
            //            continue;
            //        }
            //        if (poleM.getGlobalBounds().contains(mousePosF))
            //        {
            //            cin >> mail;
            //        
            //            wyswietlMail.setString(mail);
     //        }
            //        if (poleH.getGlobalBounds().contains(mousePosF))
            //        {
            //            cin >> password;
            //            wyswietlHaslo.setString(password);
            //        }
            //    }
            //    if (menu.GoodPassword(mail, password))
            //    {
            //        menu.SetStatus(true);
            //        menu.logged=menu.GetSpecificKlient(mail);
            //    }
            //    //----Rysowanie---
            //    window.clear(sf::Color(230, 165, 190));
            //    window.draw(text);
            //    window.draw(loginBtn);
            //    window.draw(rejestracjaBtn);
            //    window.draw(poleM);
            //    window.draw(login);
            //    window.draw(poleH);
            //    window.draw(haslo);
            //    window.draw(wyswietlMail);
            //    window.draw(wyswietlHaslo);
            //    if (nieudalo==true)
            //    {
            //        window.draw(alert);
            //    }
            //    if (menu.Email_check(mail) == false && mail!="")
            //    {
            //        alert.setString("Zla forma email");
            //        alert.setPosition((width / 2 - alert.getLocalBounds().width / 2 - 200), 1000);
            //        window.draw(alert);
            //    }


                 if (event.type == sf::Event::Closed)     //zamyka onko 
                {
                    window.close();
                }
                window.clear(sf::Color(230, 165, 190));
                widok.Panel0(window,event,menu,panel);

                //wypisywanie tekstu w obszarze mail
                if (widok.boolMail && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.mail.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.mail.pop_back();
                        widok.wyswietlMail.setString(widok.mail);
                    }
                    else if (event.text.unicode != 8 && widok.mail.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.mail.push_back(static_cast<char>(event.text.unicode));
                        widok.wyswietlMail.setString(widok.mail);
                    }
                }
                //wypisywanie tekstu w obszarze password
                if (widok.boolPassword && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.password.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.password.pop_back();
                        widok.wyswietlHaslo.setString(widok.markPassword(widok.password));
                    }
                    else if (event.text.unicode != 8 && widok.password.length() < 19) //wpisywanie tekstu max 19znaków
                    {
                        widok.password.push_back(static_cast<char>(event.text.unicode));
                        widok.wyswietlHaslo.setString(widok.markPassword(widok.password));
                    }
                }
                //if zatrzymujący wpisywanie tekstu po kliknięciu entera dla mejl lub password
                if (widok.boolMail || widok.boolPassword && event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        widok.boolMail = false;
                        widok.boolPassword = false;
                        if (menu.Email_check(widok.mail) == false && widok.mail != "")
                        {
                            widok.alert.setString("Zla forma email");
                            widok.alert.setPosition((widok.width / 2 - widok.alert.getLocalBounds().width / 2 - 200), 1000);
                            
                        }
                    }
                }

               window.draw(widok.alert);
               

               
            }
            
             if (panel == 1)
             {
                 if (event.type == sf::Event::Closed)        //zamyka onko 
                 {
                     window.close();
                 }


                 window.clear(sf::Color(230, 165, 190));
                 widok.Panel1(window, event, menu, panel);
                
                 //------Ustawianie----------
               
              
                 
                 //sf::Text registerBtn = widok.Napis("Zarejestruj sie", 60, widok.width / 2 - 425 / 2, 1400);

                 


                 if (event.type == sf::Event::MouseButtonPressed) //czy myszka i wcisnieta
                 {
                     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                     sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                     if (widok.poleI.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 0)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }

                     if (widok.poleN.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 1)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }
                     if (widok.poleMR.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 2)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }
                     if (widok.poleHR.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 3)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }
                     if (widok.poleP.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 4)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }
                     if (widok.poleA.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 5)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }
                     if (widok.poleD.getGlobalBounds().contains(mousePosF))
                     {
                         for (int i = 0; i < 7; i++)
                         {
                             if (i == 6)
                                 widok.statusPola[i] = true;
                             else
                                 widok.statusPola[i] = false;
                         }
                     }

                 }

                 //wypisywanie tekstu w obszarze imie
                 if (widok.statusPola[0] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.imie.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.imie.pop_back();
                         widok.imieT.setString(widok.imie);
                     }
                     else if (event.text.unicode != 8 && widok.imie.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.imie.push_back(static_cast<char>(event.text.unicode));
                         widok.imieT.setString(widok.imie);
                     }
                 }
                 //wypisywanie tekstu w obszarze nazwisko
                 if (widok.statusPola[1] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.nazwisko.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.nazwisko.pop_back();
                         widok.nazwiskoT.setString(widok.nazwisko);
                     }
                     else if (event.text.unicode != 8 && widok.nazwisko.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.nazwisko.push_back(static_cast<char>(event.text.unicode));
                         widok.nazwiskoT.setString(widok.nazwisko);
                     }
                 }
                 //wypisywanie tekstu w obszarze mail
                 if (widok.statusPola[2] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.mailR.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.mailR.pop_back();
                         widok.mailT.setString(widok.mailR);
                     }
                     else if (event.text.unicode != 8 && widok.mailR.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.mailR.push_back(static_cast<char>(event.text.unicode));
                         widok.mailT.setString(widok.mailR);
                     }
                 }
                 //wypisywanie tekstu w obszarze haslo
                 if (widok.statusPola[3] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.hasloR.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.hasloR.pop_back();
                         widok.hasloT.setString(widok.hasloR);
                     }
                     else if (event.text.unicode != 8 && widok.hasloR.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.hasloR.push_back(static_cast<char>(event.text.unicode));
                         widok.hasloT.setString(widok.hasloR);
                     }
                 }
                 //wypisywanie tekstu w obszarze pesel
                 if (widok.statusPola[4] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.pesel.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.pesel.pop_back();
                         widok.peselT.setString(widok.pesel);
                     }
                     else if (event.text.unicode != 8 && widok.pesel.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.pesel.push_back(static_cast<char>(event.text.unicode));
                         widok.peselT.setString(widok.pesel);
                     }
                 }
                 //wypisywanie tekstu w obszarze adres
                 if (widok.statusPola[5] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.adres.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.adres.pop_back();
                         widok.adresT.setString(widok.adres);
                     }
                     else if (event.text.unicode != 8 && widok.adres.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.adres.push_back(static_cast<char>(event.text.unicode));
                         widok.adresT.setString(widok.adres);
                     }
                 }
                 //wypisywanie tekstu w obszarze nrdowodT
                 if (widok.statusPola[6] && event.type == sf::Event::TextEntered)
                 {
                     if (event.text.unicode == 8 && widok.dowod.length() > 0) // usuwanie tekstu za pomocą backspace
                     {
                         widok.dowod.pop_back();
                         widok.nrdowodT.setString(widok.dowod);
                     }
                     else if (event.text.unicode != 8 && widok.dowod.length() < 19) //wpisywanie tekstu max 19znaków
                     {
                         widok.dowod.push_back(static_cast<char>(event.text.unicode));
                         widok.nrdowodT.setString(widok.dowod);
                     }
                 }
                 //if zatrzymujący wpisywanie tekstu po kliknięciu entera dla mejl lub password
                 if (widok.statusPola[0] || widok.statusPola[1] || widok.statusPola[2] || widok.statusPola[3] || widok.statusPola[4] || widok.statusPola[5] || widok.statusPola[6] && event.type == sf::Event::KeyPressed)
                 {
                     if (event.key.code == sf::Keyboard::Enter)
                     {
                         for (int i = 0; i < 7; i++)
                             widok.statusPola[i]=false;

                     }
                 }
             
                // //----Rysowanie---
            
           
                /* window.draw(widok.poleI);
                 window.draw(poleN);
                 window.draw(poleM);
                 window.draw(poleH);
                 window.draw(poleP);
                 window.draw(poleA);
                 window.draw(poleD);
                 window.draw(registerBtn);
                 window.draw(widok.imieT);
                 window.draw(nazwiskoT);
                 window.draw(mailT);
                 window.draw(hasloT);
                 window.draw(peselT);
                 window.draw(adresT);
                 window.draw(nrdowodT);*/
             }
            

             if (panel == 2)                                 //Konta
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }
                //------Ustawianie----------
               

                widok.Zalogowany(window,menu);
                widok.Panel2(window, event, menu, panel);


            }


            if (panel == 3)                         
            {
                widok.Panel3Transakcja(window, event, menu, panel);

                //wypisywanie tekstu w obszarze kwota
                if (widok.statusPolTransakcja[0] && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.kwota.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.kwota.pop_back();
                        widok.kwotaT.setString(widok.kwota);
                    }
                    else if (event.text.unicode != 8 && widok.kwota.length() < 19) //wpisywanie tekstu max 19znaków
                    {
                        widok.kwota.push_back(static_cast<char>(event.text.unicode));
                        widok.kwotaT.setString(widok.kwota);
                    }
                }
                //wypisywanie tekstu w obszarze tytul
                if (widok.statusPolTransakcja[1] && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.tytul.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.tytul.pop_back();
                        widok.tytulT.setString(widok.tytul);
                    }
                    else if (event.text.unicode != 8 && widok.tytul.length() < 19) //wpisywanie tekstu max 19znaków
                    {
                        widok.tytul.push_back(static_cast<char>(event.text.unicode));
                        widok.tytulT.setString(widok.tytul);
                    }
                }


                if (menu.operacja->Nazwa() == "Przelew")
                {
                    //wypisywanie tekstu w obszarze odbiorca
                    if (widok.statusPolTransakcja[2] && event.type == sf::Event::TextEntered)
                    {
                        if (event.text.unicode == 8 && widok.nr_odbiorcy.length() > 0) // usuwanie tekstu za pomocą backspace
                        {
                            widok.nr_odbiorcy.pop_back();
                            widok.odbiorcaT.setString(widok.nr_odbiorcy);
                        }
                        else if (event.text.unicode != 8 && widok.nr_odbiorcy.length() < 19) //wpisywanie tekstu max 19znaków
                        {
                            widok.nr_odbiorcy.push_back(static_cast<char>(event.text.unicode));
                            widok.odbiorcaT.setString(widok.nr_odbiorcy);
                        }
                    }
                }
                if (menu.operacja->Nazwa() == "Kredyt")
                {
                    //wypisywanie tekstu w obszarze odbiorca
                    if (widok.statusPolTransakcja[3] && event.type == sf::Event::TextEntered)
                    {
                        if (event.text.unicode == 8 && widok.okres.length() > 0) // usuwanie tekstu za pomocą backspace
                        {
                            widok.okres.pop_back();
                            widok.okresT.setString(widok.okres);
                        }
                        else if (event.text.unicode != 8 && widok.okres.length() < 19) //wpisywanie tekstu max 19znaków
                        {
                            widok.okres.push_back(static_cast<char>(event.text.unicode));
                            widok.okresT.setString(widok.okres);
                        }
                    }
                }

                //if zatrzymujący wpisywanie tekstu po kliknięciu entera dla mejl lub password
                if (widok.statusPolTransakcja[0] || widok.statusPolTransakcja[1]||widok.statusPolTransakcja[2]||widok.statusPolTransakcja[3] && event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                       
                        widok.statusPolTransakcja[0] = false;
                        widok.statusPolTransakcja[1] = false;
                        widok.statusPolTransakcja[2] = false;
                        widok.statusPolTransakcja[3] = false;
                        if ((CzyLiczba(widok.kwota) == false && widok.kwota != "") || (CzyTekst(widok.tytul)==false&&widok.tytul!="")|| (menu.operacja->Nazwa() == "Przelew" && CzyLiczba(widok.nr_odbiorcy)==false && widok.nr_odbiorcy != "")
                            || (menu.operacja->Nazwa() == "Kredyt" && CzyLiczba(widok.okres) == false && widok.okres != ""))
                        {
                            widok.alert.setString("Zle dane");
                            widok.alert.setPosition((widok.width / 2 - widok.alert.getLocalBounds().width / 2 - 200), 1000);

                        }

            
                    }
                }

            } 
            
            if (panel == 4)
            {
                widok.PanelKontaBankowego4(window,event,widok.UstawKonto,menu,panel);
            }
              
            if (panel == 5)
            {

                widok.Panel5ZmianaHasla(window, event, menu, panel);

                //wypisywanie tekstu w obszarze starehaslo
                if (widok.boolstareHaslo && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.stareHaslo.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.stareHaslo.pop_back();
                        widok.starehasloT.setString(widok.stareHaslo);
                    }
                    else if (event.text.unicode != 8 && widok.stareHaslo.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.stareHaslo.push_back(static_cast<char>(event.text.unicode));
                        widok.starehasloT.setString(widok.stareHaslo);
                    }
                }
                //wypisywanie tekstu w obszarze nowehaslo
                if (widok.boolnoweHaslo && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.noweHaslo.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.noweHaslo.pop_back();
                        widok.nowehasloT.setString(widok.noweHaslo);
                    }
                    else if (event.text.unicode != 8 && widok.noweHaslo.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.noweHaslo.push_back(static_cast<char>(event.text.unicode));
                        widok.nowehasloT.setString(widok.noweHaslo);
                    }
                }
                //if zatrzymujący wpisywanie tekstu po kliknięciu entera 
                if (widok.boolstareHaslo || widok.boolnoweHaslo && event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        widok.boolstareHaslo = false;
                        widok.boolnoweHaslo = false;
                    }
                }


            }

            if (panel == 6)
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }
                widok.Panel6Admin(window, event, menu, panel);
            }
            if (panel == 7)
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }

                //wypisywanie tekstu w obszarze nowehaslo
                if (widok.IdOsobyB && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.IdOsoby.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.IdOsoby.pop_back();
                        widok.IdOsobyT.setString(widok.IdOsoby);
                    }
                    else if (event.text.unicode != 8 && widok.IdOsoby.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.IdOsoby.push_back(static_cast<char>(event.text.unicode));
                        widok.IdOsobyT.setString(widok.IdOsoby);
                    }
                }
                //if zatrzymujący wpisywanie tekstu po kliknięciu entera 
                if (widok.IdOsobyB  && event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        widok.IdOsobyB = false;
                        //widok.boolnoweHaslo = false;
                    }
                }

                widok.Panel7UsunUzytkownika(window, event, menu, panel);

            }
            if (panel == 8)
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }

                //wypisywanie tekstu w obszarze nowehaslo
                if (widok.IdOsobyB && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.IdOsoby.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.IdOsoby.pop_back();
                        widok.IdOsobyT.setString(widok.IdOsoby);
                    }
                    else if (event.text.unicode != 8 && widok.IdOsoby.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.IdOsoby.push_back(static_cast<char>(event.text.unicode));
                        widok.IdOsobyT.setString(widok.IdOsoby);
                    }
                }
                //if zatrzymujący wpisywanie tekstu po kliknięciu entera 
                if (widok.IdOsobyB && event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        widok.IdOsobyB = false;
                        //widok.boolnoweHaslo = false;
                    }
                }


                widok.Panel8ZnajdzKonto(window, event, menu, panel);

            }

            if (panel == 9)
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }
                widok.Panel9KontozTrans(window, event, menu, panel);
            }
            if (panel == 10)
            {
                if (event.type == sf::Event::Closed)    //zamka okno
                {
                    window.close();
                }

                //wypisywanie tekstu w obszarze id
                if (widok.boolid && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.id.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.id.pop_back();
                        widok.idT.setString(widok.id);
                    }
                    else if (event.text.unicode != 8 && widok.id.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.id.push_back(static_cast<char>(event.text.unicode));
                        widok.idT.setString(widok.id);
                    }
                }
                //wypisywanie tekstu w obszarze mail
                if (widok.boolmailNew && event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 8 && widok.mailNew.length() > 0) // usuwanie tekstu za pomocą backspace
                    {
                        widok.mailNew.pop_back();
                        widok.mailNewT.setString(widok.mailNew);
                    }
                    else if (event.text.unicode != 8 && widok.mailNew.length() < 19) // wpisywanie tekstu max 19znaków
                    {
                        widok.mailNew.push_back(static_cast<char>(event.text.unicode));
                        widok.mailNewT.setString(widok.mailNew);
                    }
                }
                //if zatrzymujący wpisywanie tekstu po kliknięciu entera 
                if (widok.boolid || widok.boolmailNew && event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        widok.boolid = false;
                        widok.boolmailNew = false;
                    }
                }
                widok.Panel10Modyfikuj(window, event, menu, panel);
            }

            if (panel == 11)
            {
                widok.Panel11OsobyZKontem(window, event, menu, panel);

            }
            }
            
            window.display();
            }

            menu.SaveBaza();
            return 0;
    }
    

    
