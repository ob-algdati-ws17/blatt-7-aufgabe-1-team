https://github.com/ob-algdati-ws17/blatt-7-aufgabe-1-team


Algorithmen und Datenstrukturen I:
Blatt 7
Prof. Dr. Oliver Braun
Fakult�t f�r Informatik und Mathematik
Hochschule M�nchen
Letzte �nderung: 03.12.2017 14:00
Achtung:
Bitte beachten Sie
https://github.com/ob-algdati-ws17/ob-algdati-ws17/
issues/2
zur ersten Abgabe. Sollten Sie die erste Abgabe nicht bestanden haben, k�n-
nen Sie auch mit diesem Blatt den Schein nicht mehr bekommen.
Aufgabe 1
Diese Aufgabe kann alleine oder in einer Zweiergruppe bearbeiten und eingereicht wer-
den. �ber den
GitHub Classroom Link
k�nnen Sie ein Team erstellen oder einem bereits
erstellten Team beitreten. Auch wenn Sie alleine arbeiten, m�ssen Sie das als �Einer-
team� machen. Das Team bekommt ein gemeinsames, leeres Repository. Zur Erf�llung
dieser Aufgabe muss folgendes bis zum
14.01.2018, 20:00
umgesetzt sein:
1.
Implementieren Sie einen AVL-Baum (siehe Ottmann & Widmayer, Algorithmen
und Datenstrukturen, Abschnitt 5.2.1) als Bibliothek in C++. Der AVL-Baum soll
kein
Template sein, sondern enth�lt nur
int
s als Schl�ssel.
2.
Die stichprobenartige Qualit�tssicherung der Bibliothek erfolgt mit Googletest.
3.
Das Projekt muss inkl. Tests mit CMake gebaut werden k�nnen.
4.
Der Build und die Tests werden mit einem
Travis-Job
ausgef�hrt, der bei jedem
Push auf GitHub getriggert wird.
Anmerkung: F�r die Freischaltung ihres Projektes auf der Travis-Plattform erzeu-
gen Sie ein Issue und weisen es mir zu. Sie haben nicht die notwendigen Rechte
das selbst zu tun.
5.
Die Datei
README.md
enth�lt einen Link auf Ihre GitHub-Page.
1
Algorithmen und Datenstrukturen I: Blatt 7
Prof. Dr. Oliver Braun
Zus�tzlich muss in eine Zweierteam folgendes umgesetzt werden:
1.
Die Googletest-Testsuite sichert die Qualit�t der Bibliothek in einem sehr hohen
Ma�.
2.
Das �ffentliche Interface des AVL-Baumes ist mit
Doxygen
dokumentiert und als
GitHub-Page
ver�ffentlicht.
Im Januar wird diese Aufgabe teamweise w�hrend der Praktikumstermine von mir ab-
genommen. Tragen Sie sich dazu im
Wiki
ein.
Tipps und Anmerkungen
�
k�mmern Sie sich als allererstes um die Travis-Anbindung
�
schreiben Sie immer gleich Tests
�
committen und pushen Sie so oft wie m�glich.
und schreiben Sie
vern�nftige
Commit-Messages!
Die Repositories f�r diese Aufgabe m�ssen wegen der Travis-Anbindung �ffentlich sein.
Sie k�nnen sich also durchaus in den anderen Repositories anschauen, wie die Kommi-
litonen etwas gel�st haben, z.B. die Travis-Anbindung. L�sen Sie die Aufgabe dennoch
auf Ihre Weise. Plagiieren f�hrt zu Nichtbestehen des Scheines und stellt nach den g�l-
tigen Gesetzen mindesten eine Ordnungswidrigkeit dar und kann damit noch weitere
rechtliche Konsequenzen nach sich ziehen.
Letzte �nderung: 03.12.2017 14:00
2
