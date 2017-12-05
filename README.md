https://github.com/ob-algdati-ws17/blatt-7-aufgabe-1-team


Algorithmen und Datenstrukturen I:
Blatt 7
Prof. Dr. Oliver Braun
Fakultät für Informatik und Mathematik
Hochschule München
Letzte Änderung: 03.12.2017 14:00
Achtung:
Bitte beachten Sie
https://github.com/ob-algdati-ws17/ob-algdati-ws17/
issues/2
zur ersten Abgabe. Sollten Sie die erste Abgabe nicht bestanden haben, kön-
nen Sie auch mit diesem Blatt den Schein nicht mehr bekommen.
Aufgabe 1
Diese Aufgabe kann alleine oder in einer Zweiergruppe bearbeiten und eingereicht wer-
den. Über den
GitHub Classroom Link
können Sie ein Team erstellen oder einem bereits
erstellten Team beitreten. Auch wenn Sie alleine arbeiten, müssen Sie das als “Einer-
team” machen. Das Team bekommt ein gemeinsames, leeres Repository. Zur Erfüllung
dieser Aufgabe muss folgendes bis zum
14.01.2018, 20:00
umgesetzt sein:
1.
Implementieren Sie einen AVL-Baum (siehe Ottmann & Widmayer, Algorithmen
und Datenstrukturen, Abschnitt 5.2.1) als Bibliothek in C++. Der AVL-Baum soll
kein
Template sein, sondern enthält nur
int
s als Schlüssel.
2.
Die stichprobenartige Qualitätssicherung der Bibliothek erfolgt mit Googletest.
3.
Das Projekt muss inkl. Tests mit CMake gebaut werden können.
4.
Der Build und die Tests werden mit einem
Travis-Job
ausgeführt, der bei jedem
Push auf GitHub getriggert wird.
Anmerkung: Für die Freischaltung ihres Projektes auf der Travis-Plattform erzeu-
gen Sie ein Issue und weisen es mir zu. Sie haben nicht die notwendigen Rechte
das selbst zu tun.
5.
Die Datei
README.md
enthält einen Link auf Ihre GitHub-Page.
1
Algorithmen und Datenstrukturen I: Blatt 7
Prof. Dr. Oliver Braun
Zusätzlich muss in eine Zweierteam folgendes umgesetzt werden:
1.
Die Googletest-Testsuite sichert die Qualität der Bibliothek in einem sehr hohen
Maß.
2.
Das öffentliche Interface des AVL-Baumes ist mit
Doxygen
dokumentiert und als
GitHub-Page
veröffentlicht.
Im Januar wird diese Aufgabe teamweise während der Praktikumstermine von mir ab-
genommen. Tragen Sie sich dazu im
Wiki
ein.
Tipps und Anmerkungen
•
kümmern Sie sich als allererstes um die Travis-Anbindung
•
schreiben Sie immer gleich Tests
•
committen und pushen Sie so oft wie möglich.
und schreiben Sie
vernünftige
Commit-Messages!
Die Repositories für diese Aufgabe müssen wegen der Travis-Anbindung öffentlich sein.
Sie können sich also durchaus in den anderen Repositories anschauen, wie die Kommi-
litonen etwas gelöst haben, z.B. die Travis-Anbindung. Lösen Sie die Aufgabe dennoch
auf Ihre Weise. Plagiieren führt zu Nichtbestehen des Scheines und stellt nach den gül-
tigen Gesetzen mindesten eine Ordnungswidrigkeit dar und kann damit noch weitere
rechtliche Konsequenzen nach sich ziehen.
Letzte Änderung: 03.12.2017 14:00
2
