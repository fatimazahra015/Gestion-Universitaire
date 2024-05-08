#include<iostream>
#include <vector>

#include "uni.hpp"

using namespace std;

int main() {
    GestionEtudiant gestion1;
    GestionPersonnel gestion2;
    Gestion_Cours gestion3(gestion2);
    Gestion_Notes gestion4;
    GestionAbsence gestion5;
    Etudiant E1("1","Mohamed","azzam","3IIR", "Informatique", "EMSI AGDAL");
    Etudiant E2("2","Riyad", "maj","3IIR", "Informatique", "EMSI BOURG");
    gestion1.CreationEtudiant(E1);
    gestion1.CreationEtudiant(E2);
    Enseignant Enseignant1("AECSWE","Siham","s","INFO","POO");
    Enseignant Enseignant2("Porf1","Hamza","a","TCPIP","Linux");
    Administratif Admin1("AGWSEHIS","Ayoub","s","Direction","Surveillance");
    gestion2.CreationEnseignant(Enseignant1);
    gestion2.CreationEnseignant(Enseignant2);
    gestion2.CreationAdministratif(Admin1);
    Cours Cours1(1,"POO","INFO","3IIR");
    Cours Cours2(2,"Linux","GenieCivil","3IIR");
    Cours Cours3(3,"Mecanic","IFA","5IFA");
    Cours Cours4(4,"TCPIP","Reseau","2ap");
    Cours Cours5(5,"Compta","Gesion","3IIR");
    gestion3.CreationCours(Cours1);
    gestion3.CreationCours(Cours2);
    gestion3.CreationCours(Cours3);
    gestion3.CreationCours(Cours4);
    gestion3.CreationCours(Cours5);
    gestion3.attribuerenseignant(1,&Enseignant1);
    gestion3.attribuerenseignant(2,&Enseignant2);
    Note note1(E1,Cours2,16);
    gestion4.CreationNote(note1);
    EmploiDuTemps Emp1(gestion3,gestion2);
    
    int choix;
    do{
        cout << endl;
        cout << "º***********************************************************************º" << endl;
        cout << "º                                                                       º" << endl;
        cout << "º                           Bienvenue a L'EMSI                          º" << endl;
        cout << "º                                                                       º" << endl;
        cout << "º***********************************************************************º" << endl;
        cout << "º                           MENU PRINCIPAL                              º" << endl;
        cout << "º***********************************************************************º" << endl;
        cout << "º    [ 1 ] - Gestion des etudiants                                      º" << endl;
        cout << "º    [ 2 ] - Gestion des enseignants                                    º" << endl;
        cout << "º    [ 3 ] - Gestion du personnel administratif                         º" << endl;
        cout << "º    [ 4 ] - Gestion des cours                                          º" << endl;
        cout << "º    [ 5 ] - Gestion des notes et absences                              º" << endl;
        cout << "º    [ 6 ] - Inscription au cours                                       º" << endl;
        cout << "º    [ 7 ] - Quitter                                                    º" << endl;
        cout << "º***********************************************************************º" << endl;
        cout << "º -> Veuillez choisir une option en entrant le numero correspondant : ";
        cin >> choix;
        switch(choix){
                case 1:{
                    int choixEtudiant;
                    do{
                        cout << "º********************************************************************º" << endl;
                        cout << "º                       MENU GESTION DES ETUDIANTS                   º" << endl;
                        cout << "º********************************************************************º" << endl;
                        cout << "º    [ 1 ] - Ajouter un nouvel etudiant                              º" << endl;
                        cout << "º    [ 2 ] - Modifier les informations d'un etudiant existant        º" << endl;
                        cout << "º    [ 3 ] - Supprimer un etudiant                                   º" << endl;
                        cout << "º    [ 4 ] - Rechercher un etudiant                                  º" << endl;
                        cout << "º    [ 5 ] - Afficher tous les etudiants                             º" << endl;
                        cout << "º    [ 6 ] - Retour au menu principal                                º" << endl;
                        cout << "º********************************************************************º" << endl;
                        cout << "º -> Veuillez choisir une option en entrant le numero correspondant : ";
                        cin >> choixEtudiant;
                        switch(choixEtudiant){
                            case 1:{
                                string  mat ,nom, prenom, filiere, niv, site;
                                cout << "Veuillez saisir le matricule de l'etudiant : ";
                                cin >> mat;
                                cout << "Veuillez saisir le nom de l'etudiant : ";
                                cin >> nom;
                                cout << "Veuillez saisir le prenom de l'etudiant : ";
                                cin >> prenom;
                                cout << "Veuillez saisir la filiere de l'etudiant : ";
                                cin >> filiere;
                                cout << "Veuillez saisir le Niveau de  l'etudiant : ";
                                cin >> niv;
                                cout << "Veuillez saisir le site de l'etudiant : ";
                                cin >> site;
                                Etudiant nouvelEtudiant(mat,nom, prenom,niv,filiere, site);
                                gestion1.CreationEtudiant(nouvelEtudiant);
                                break;
                            }case 2:{
                                gestion1.ModifierEtudiant();
                                break;
                            }case 3:{
                                string mat;
                                cout << "Veuillez saisir le matricule de l'etudiant a supprimer : ";
                                cin >> mat;
                                gestion1.SupprimerEtudiant(mat);
                                break;
                            }case 4:{
                                string mat;
                                cout << "Veuillez saisir le matricule de l'etudiant : ";
                                cin >> mat;
                                gestion1.RechercheEtudiant(mat);
                                break;
                            }case 5:{
                                gestion1.AfficherDetailsEtudiant();
                                break;
                            }case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez saisir un numero valide." << endl;
                                break;
                        }
                    } while (choixEtudiant != 6); 
                    break;
                }case 2:{
                    int choixEnseignant;
                    do {
                        cout << "º********************************************************************º" << endl;
                        cout << "º                       MENU GESTION DES ENSEIGNANTS                 º" << endl;
                        cout << "º********************************************************************º" << endl;
                        cout << "º    [ 1 ] - Ajouter un nouvel enseignant                            º" << endl;
                        cout << "º    [ 2 ] - Modifier les informations d'un enseignant existant      º" << endl;
                        cout << "º    [ 3 ] - Supprimer un enseignant                                 º" << endl;
                        cout << "º    [ 4 ] - Rechercher un enseignant                                º" << endl;
                        cout << "º    [ 5 ] - Afficher tous les enseignant                            º" << endl;
                        cout << "º    [ 6 ] - Retour au menu principal                                º" << endl;
                        cout << "º********************************************************************º" << endl;
                        cout << "Veuillez choisir une option en entrant le numero correspondant : ";
                        cin >> choixEnseignant;
                        switch (choixEnseignant) {
                            case 1:{
                                string matri,n,p,d,matiere;
                                cout << "Veuillez saisir le Matricule : ";
                                cin >> matri;
                                cout << "Veuillez saisir le Nom D'enseignant : ";
                                cin >> n;
                                cout << "Veuillez saisir le Prenom D'enseignant : ";
                                cin >> p;
                                cout << "Veuillez saisir le Departement : ";
                                cin >> d;
                                cout << "Veuillez saisir la matiere : ";
                                cin >> matiere;
                                Enseignant Enseignant3(matri,n,p,d,matiere);
                                gestion2.CreationEnseignant(Enseignant3);
                                break;
                            }case 2:{
                                gestion2.ModifierEnseigant();
                                break;
                            }case 3:{
                                string mat;
                                cout << "Veuillez saisir le matricule de l'enseignant : ";
                                cin >> mat;
                                gestion2.SupprimerEnseignant(mat);
                                break;
                            }case 4:{
                                string mat;
                                cout << "Matricule d'enseignant a chercher : ";
                                cin >> mat;
                                gestion2.RechercheEnseignant(mat);
                                break;
                            }case 5:{
                                gestion2.AfficherTousLesEnseignant();
                                break;
                            }case 6:{
                                cout << "Retour au menu principal." << endl;
                                break;
                            }default:
                                cout << "Option invalide. Veuillez saisir un numero valide." << endl;
                                break;
                        }
                    }while (choixEnseignant != 6); 
                    break;
                }case 3:{
                    int choixAdmin;
                    do {
                        cout << "º***********************************************************************º" << endl;
                        cout << "º                 MENU GESTION DU PERSONNEL ADMINISTRATIF              º" << endl;
                        cout << "º**********************************************************************º" << endl;
                        cout << "º                                                                      º"  << endl;
                        cout << "º  [ 1 ]  Ajouter un nouveau membre du personnel administratif         º" << endl;
                        cout << "º  [ 2 ]  Modifier les informations d'un membre du personnel           º" << endl;
                        cout << "º  [ 3 ]  Supprimer un membre du personnel administratif               º" << endl;
                        cout << "º  [ 4 ]  Rechercher un membre du personnel administratif              º" << endl;
                        cout << "º  [ 5 ]  Afficher tous les membres du personnel administratif         º" << endl;
                        cout << "º  [ 6 ]  Retour au menu principal                                     º" << endl;
                        cout << "º                                                                      º"  << endl;
                        cout << "º**********************************************************************º" << endl;
                        cout << "º | Veuillez choisir une option en entrant le numero correspondant : ";
                        cin >> choixAdmin;
                        switch(choixAdmin) {
                            case 1:{
                                string matri,n,p,d,poste;
                                cout << "Veuillez saisir le Matricule : ";
                                cin >> matri;
                                cout << "Veuillez saisir le Nom D'Administratif : ";
                                cin >> n;
                                cout << "Veuillez saisir le Prenom D'Administratif : ";
                                cin >> p;
                                cout << "Veuillez saisir le Departement : ";
                                cin >> d;
                                cout << "Veuillez saisir le poste : ";
                                cin >> poste;
                                Administratif Admin2(matri,n,p,d,poste);
                                gestion2.CreationAdministratif(Admin2);
                                cout << "Nouveau membre du personnel administratif ajouté avec succès !" << endl;
                                break;
                            }case 2:{
                                gestion2.ModifierAdmin();
                                break;
                            } case 3:{
                                string mate;
                                cout <<"Entrer le matricule de l'administratif : " <<  endl;
                                cin >> mate;
                                gestion2.SupprimerAdministratif(mate);
                                break;
                            }
                                break;
                            case 4:{
                                string mat;
                                cout << "Matricule d'Administratif a chercher : ";
                                cin >> mat;
                                gestion2.RechercheAdministratif(mat);
                                break;
                            }case 5:{
                                gestion2.AfficherTousLesAdmin();
                                break;
                            }case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez saisir un numero valide." << endl;
                                break;
                        }
                    }while (choixAdmin != 6);
                    break;
                }case 4:{
                    int choixCours;
                    do {
                        cout << "º**************************************************************º" << endl;
                        cout << "º               MENU GESTION DES COURS                         º" << endl;
                        cout << "º**************************************************************º" << endl;
                        cout << "º                                                              º" << endl;
                        cout << "º  [ 1 ]  Ajouter un nouveau cours                             º" << endl;
                        cout << "º  [ 2 ]  Modifier les informations d'un cours existant        º" << endl;
                        cout << "º  [ 3 ]  Supprimer un cours                                   º" << endl;
                        cout << "º  [ 4 ]  Consulter un cours                                   º" << endl;
                        cout << "º  [ 5 ]  Afficher les Cours                                   º" << endl;
                        cout << "º  [ 6 ]  Retour au menu principal                             º" << endl;
                        cout << "º                                                              º"  << endl;
                        cout << "º**************************************************************º" << endl;
                        cout << "Veuillez choisir une option en entrant le numero correspondant : ";
                        cin >> choixCours;
                        switch(choixCours) {
                            case 1:{
                                int i;
                                string nom, f,n;
                                cout << "Veuillez saisir l'identifiant du cours : ";
                                cin >> i;
                                cout << "Veuillez saisir le nom du cours : ";
                                cin >> nom;
                                cout << "Veuillez saisir la Filliere du cours: ";
                                cin >> f;
                                cout << "Veuillez saisir le niveau d'etude du cours : ";
                                cin >> n;
                                Cours C6(i,nom,f,n);
                                gestion3.CreationCours(C6);
                                break;
                            }case 2:{
                                string cours;
                                cout << "Veuillez saisir le nom du cours a modifier : ";
                                cin >> cours;
                                gestion3.ModifierCours(cours);
                                break;
                            }case 3:{
                                int cours;
                                cout << "Veuillez saisir l' ID cours a supprimer : ";
                                cin >> cours;
                                gestion3.SupprimerCours(cours);
                                cout << "Cours supprimer : "<<endl;
                                break;
                            }case 4:{
                                string dep,niv;
                                cout << "Veuillez saisir le Departement : ";
                                cin >> dep;
                                cout << "Veuillez saisir Le Niveau D'etude : ";
                                cin >> niv;
                                gestion3.ConsulterCours(dep,niv);
                                break;
                            }case 5:{
                                gestion3.affichertouslescours();
                                break;
                            }case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez saisir un numero valide." << endl;
                                break;
                        }
                    }while (choixCours != 6);
                        break;
                }case 5:{
                    int choixnote;
                    do{
                        cout << "º**********************************************º" << endl;
                        cout << "º      MENU Gestion des notes et absences      º" << endl;
                        cout << "º**********************************************º" << endl;
                        cout << "º                                              º" << endl;
                        cout << "º  [ 1 ]  Consulter Les Notes                  º" << endl;
                        cout << "º  [ 2 ]  Modifier une Note                    º" << endl;
                        cout << "º  [ 3 ]  Ajouter une absence                  º" << endl;
                        cout << "º  [ 4 ]  Afficher Les Absense                 º" << endl;
                        cout << "º  [ 5 ]  Justification d'abscence             º" << endl;
                        cout << "º  [ 6 ]  Retour au menu principal             º" << endl;
                        cout << "º                                              º" << endl;
                        cout << "º**********************************************º" << endl;
                        cout << "Veuillez choisir une option en entrant le numero correspondant : ";
                        cin >> choixnote;
                        switch (choixnote){
                            case 1:{
                                gestion4.ConsulterlesNote();
                                break;
                            }case 2:{
                                string matricule;
                                cout << "Veuillez saisir le matricule de l'etudiant : ";
                                cin >> matricule;
                                bool existeetudiant = false;
                                for (auto e : gestion1.getEtudiants()){
                                    if (e.getMat() == matricule) {
                                        existeetudiant = true;
                                        string cours;
                                        cout << "Veuillez saisir le Nom du cours : ";
                                        cin >> cours;
                                        bool co = false;
                                        for (auto c : gestion3.getListeDesCours()) {
                                            if (c.getNomCours() == cours) {
                                                co = true;
                                                double note;
                                                cout << "Veuillez saisir la Nouvelle note : ";
                                                cin >> note;
                                                gestion4.ModifierNote(note);
                                                break;
                                            }
                                        }
                                        if (!co) {
                                            cout << "Ce cours n'existe pas" << endl;
                                            break;
                                        }
                                    }
                                }
                                if (!existeetudiant) {
                                    cout << "Cet etudiant n'existe pas" << endl;
                                }
                                break;
                            }case 3:{
                                string m,c,d,h;
                                cout << "Veuillez saisir Le Matricule D'etudiant : ";
                                cin >> m;
                                cout << "Veuillez saisir Le Cours D'etudiant : ";
                                cin >> c;
                                cout << "Veuillez saisir La Date D'abscence : ";
                                cin >> d;
                                cout << "Veuillez saisir l'heure : ";
                                cin >>h;
                                Etudiant* etudiant = gestion1.rechercherEtudiantParNom(m);
                                Cours* cours = gestion3.rechercherCoursParNom(c);
                                gestion5.creerAbsence(etudiant,cours,d,h);
                                break;
                            }case 4:{
                                gestion5.Abscenceetudiant();
                                break;
                            }case 5:{
                                string matricule;
                                cout << "Veuillez saisir le matricule de l'etudiant : ";
                                cin >> matricule;
                                cout << "Veuillez saisir La Date D'abscence : ";
                                string date;
                                cin >> date;
                                cout << "Motif (justifiée [Oui] ou non justifiée [Non]) : ";
                                string newstatut;
                                cin >> newstatut;
                                gestion5.modifierStatutAbsenceParMatricule(matricule,newstatut,date);
                                break;
                            }case 6 :
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez saisir un numero valide." << endl;
                                break;
                        }
                    }while (choixnote != 6);
                    break;
                }case 6:{
                    int choixinsciption;
                    do{
                        cout << "º**********************************************º" << endl;
                        cout << "º            Inscription Au Cours              º" << endl;
                        cout << "º**********************************************º" << endl;
                        cout << "º                                              º" << endl;
                        cout << "º        [ 1 ]  Inscription Au Cours           º" << endl;
                        cout << "º        [ 2 ]  Valider L'inscription          º" << endl;
                        cout << "º        [ 3 ]  Emploi du Temps                º" << endl;
                        cout << "º        [ 4 ]  REmplir Emploi                 º" << endl;
                        cout << "º        [ 5 ]  Modifier Emploi                º" << endl;
                        cout << "º        [ 6 ]  Retour au menu principal       º" << endl;
                        cout << "º                                              º" << endl;
                        cout << "º**********************************************º" << endl;                        
                        cout << "Entrer votre choix : ";
                        cin >> choixinsciption;
                        switch (choixinsciption){
                            case 1 :{
                                cout << "------------------ INSCRIPTION AU COURS --------------" << endl;
                                cout << "Veuillez saisir Votre Matricule : ";
                                string matricule;
                                cin >> matricule;
                                bool existetudiant = false;
                                for (auto& e : gestion1.getEtudiants()) {
                                        if (e.getMat() == matricule) {
                                            existetudiant = true;
                                            bool coursexiste = false;
                                            cout << "|-------------- Inscription Au cours --------------|" << endl;
                                            for (auto& c : gestion3.getListeDesCours()) {
                                                if (e.getNiveau() == c.getNiveauCours()) {
                                                    coursexiste = true;
                                                    cout << "| - " << c.getNomCours() << endl;
                                                }   
                                            }
                                            if (!coursexiste) {
                                                cout << "Aucun cours trouvé pour le niveau de l'etudiant" << endl;
                                            } 
                                            cout << "Nom du cours à choisir : ";
                                            string nomCoursChoisi;
                                            cin >> nomCoursChoisi;
                                            e.setCoursinscrits(nomCoursChoisi);
                                                break;
                                        }
                                }
                                    if(!existetudiant) {
                                    cout << "Etudiant Inexistant" << endl;
                                    }
                                    break;
                            }case 2:{
                                for (auto& e : gestion1.getEtudiants()){
                                    e.afficheinscription();
                                }
                                string name,val;
                                cout << "------- | Consultation des Inscription au cours |-------" << endl;
                                cout << "| - Veuillez saisir le nom d'etudiant : ";
                                cin >> name;
                                cout << "| - [ Valider | Refuser ] ";
                                cin >> val;
                                for (auto& e : gestion1.getEtudiants()){
                                    if (e.getNom() == name){
                                        if (val == "V"){
                                            e.setstatut("Valider");
                                        }else if (val == "R"){
                                            e.setstatut("Refuser");
                                        }
                                    }
                                }
                                break;
                            }case 3:{
                                Emp1.afficherEmploiDuTemps();
                                break;
                            }case 4:{
                                Emp1.remplirEmploi();
                                break;
                            }case 5:{
                                Emp1.modifierEmploi();
                            }
                            case 6:
                                cout << "Retour au menu principal." << endl;
                                break;
                            default:
                                cout << "Option invalide. Veuillez entrer un numero valide." << endl;
                                break;
                        }
                    }while(choixinsciption != 6);
                    break;
                }case 7 :{
                    cout << "Au REVOIR " << endl;
                    break;
                }default:{
                    cout << "Option invalide. Veuillez entrer un numero valide." << endl;
                    break;
                }
                }
        }while(choix != 7);
}
    
