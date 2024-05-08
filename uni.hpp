#ifndef DEF_UNI
#define DEF_UNI

#include <iostream>
#include <vector>


using namespace std;
//*************************************************************************************************************
//************************************| Class Etudiant |*******************************************************
class Etudiant {
    private:
        string  Mat;
        string  Nom;
        string  Prenom;
        string  Niveau;
        string  Filiere;
        string  Site;
        string coursinscrits;
        string statut;
        // string Password;
    public:
    //Etudiant(){};
        Etudiant(string mat,string nom,string prenom,string niveau,string filiere,string site);
        string getMat() ;
        string getNom() ;
        string getPrenom() ;
        string getNiveau() ;
        string getFiliere() ;
        string getSite();
        void setFiliere(string F);
        void setSite(string S);
        void setMat(string M);
        string getCoursinscrits();
        void setCoursinscrits(string C);
        string getstatut();
        void setstatut(string s);
        void CreationEtudiant(Etudiant& E);
        void AfficherEtudiant() ; 
        void ModifierEtudiant(string N,string S);
        void RechercheEtudiant(string M);
        void SupprimerEtudiant( string& mat);
        void afficheinscription();
        
};
//**************************************************************************************************************
//************************************| Class Gestion Etudiant |*******************************************************
class GestionEtudiant{
    private:
    vector <Etudiant> Etudiants;
    public:
    GestionEtudiant();
    vector<Etudiant>& getEtudiants();
    void  AfficherDetailsEtudiant();  
    void  CreationEtudiant(Etudiant& E);
    void  ModifierEtudiant();
    void  RechercheEtudiant(string m);
    void  SupprimerEtudiant(string mat);
    Etudiant* rechercherEtudiantParNom(string matricule);
};

//*********************************************************************************************************************
//*******************************************|->  Class Personnel <-|*******************************************************

class Personnel{
    protected:
        string MatE;
        string Nom;
        string Prenom;
        string Dep;
    public:
        Personnel(string mate,string nom, string prenom, string dep);
        string getMatE();
        string getNom();
        string getPrenom();
        string getDep();
        void setDep(string d);        
    void AfficherPersonnel();
    // void CreationPersonnel();


};
//***************************************************************************************************************
//************************************| Class Enseignant |*******************************************************
class Enseignant:public Personnel{
    private:
    string Matiere;
    public:
    Enseignant(string mate,string nom,string prenom,string dep,string mat);
    string getMatiere();
    void setMatiere(string m);
    void AfficherEnseignant();
    
};
//******************************************************************************************************************
//************************************| Class Administratif |*******************************************************
class Administratif:public Personnel{
    private:
        string Poste;
    public:
    Administratif(string mate, string nom, string prenom,  string dep, string poste);
        string getPoste(); 
        void setPoste(string p);   
    void AfficherAdministratif();
    void CreationAdministratif();
    void ModifierAdministratif();
    void SupperssionAdministratif();
    
};

//**********************************************************************************************************************
//************************************| Class Gestion Personnel |*******************************************
class GestionPersonnel{
    private:
        vector<Enseignant> ListEnsignant;
        vector<Administratif> ListAdministratif;
    public:
        GestionPersonnel();
        vector<Enseignant>& getListEnsignant();
        void CreationEnseignant(Enseignant& E);
        void CreationAdministratif(Administratif& A);
        void SupprimerEnseignant(string m);
        void SupprimerAdministratif(string m);
        void AfficherTousLesEnseignant();
        void AfficherTousLesAdmin();
        void RechercheEnseignant(string mate );
        void RechercheAdministratif(string mate );
        void ModifierAdmin();
        void ModifierEnseigant();
};

//******************************************************************************************************************
//************************************| Class Cours |*******************************************************

class Cours {
    private:
        int IdCours;
        string NomCours;
        string FiliereCours;
        string NiveauCours;
        string heure;
        string jour;
    public:
        Cours(int i,string nom,string f,string n);        
        int getIdCours();
        string getHeure();
        string getJour();
        void setHeure(string h);
        void setJour(string j);
        string getNomCours();
        string getFilierCours();
        string getNiveauCours(); 
        void setNiveauCours(string n);   
        void AfficherCours();
};

//****************************************************************************************************************


//************************************| Class Gestion Cours |*****************************************************
class Gestion_Cours{
    vector<Cours> ListeDesCours;
    Enseignant* EnseignantCours;
    GestionPersonnel& personnel;
    public :
        Gestion_Cours(GestionPersonnel& p);
        vector<Cours>& getListeDesCours();
        void CreationCours(Cours& c);
        void recherchercours(string nom);
        void ConsulterCours(string d,string n);
        void ModifierCours(string cours);
        void attribuerenseignant(int id,Enseignant* ens);
        void affichertouslescours();
        void SupprimerCours(int i);
        Enseignant* getEnseignantCours();
        Cours* rechercherCoursParNom(string nom);
        
};
//****************************************************************************************************************

//************************************| Class Note |*****************************************************
class Note{
    private:
        Etudiant& Nometudiant;
        Cours& Nomcours;
        double note;
    public:
        Note(Etudiant& etudiant,Cours& nomcours,double N);
        Etudiant& getNometudiant();
        Cours& getNomcours();
        double getNote();  
        void setNote(double n);
        void afficheNote();
};
//****************************************************************************************************************
//************************************| Class Gestion Note|*****************************************************
class Gestion_Notes{
private:
    vector<Note> ListNote;
public:
    Gestion_Notes();
    void CreationNote(Note& n);
    void ModifierNote(double NouvelleNote);
    void ConsulterlesNote();
};

//****************************************************************************************************************
//************************************| Class Absence |*****************************************************

class Absence {
private:
    Etudiant* etudiant;
    Cours* cours;
    string Date;
    string Heure;
    string motif;
public:
    Absence(Etudiant* e, Cours* c, string d,string h);
    Etudiant* getEtudiant();
    Cours* getCours();
    string getDate() ;
    void setDate(string d);
    string getHeure();
    void setHeure(string h);
    void setMotif(string m);
    string getMotif();
    void afficherAbsence();
    //~Absence();
};
//****************************************************************************************************************
//************************************| Class Gestion Absence |*****************************************************

class GestionAbsence {
private:
    vector<Absence> Listabsences;
    
public:
    GestionAbsence();
    void creerAbsence(Etudiant* etudiant, Cours* cours, string date,string heure);     
    //void supprimerAbsence(Absence& a);
    void Abscenceetudiant();

    void modifierStatutAbsenceParMatricule(string matricule, string newstatut,string date);
};






class EmploiDuTemps{
    private:
        Gestion_Cours& cours;
        GestionPersonnel& enseignant;
        string jour;
        string horaire;
        
    public:
        EmploiDuTemps(Gestion_Cours& c,GestionPersonnel& ens);
        //void ajouterCours(Cours c);
        string getJour();
        string getHoraire();
        void setJour(string nouveauJour);
        void setHoraire(string nouvelHoraire);
        void afficherEmploiDuTemps();
        void remplirEmploi();
        void modifierEmploi();
};

class Gestion_Emploi_du_emps{
    private: 
        vector<EmploiDuTemps> Emploi;
};






#endif