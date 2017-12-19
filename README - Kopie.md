https://github.com/ob-algdati-ws17/blatt-7-aufgabe-1-team
https://github.com/SimonPreisinger
https://github.com/LorMun

# Algorithmen und Datenstrukturen I:

# Blatt 7

## Prof. Dr. Oliver Braun

```
Fakult�t f�r Informatik und Mathematik
Hochschule M�nchen
```
```
Letzte �nderung: 03.12.2017 14:
```
**Achtung:** Bitte beachten Siehttps://github.com/ob-algdati-ws17/ob-algdati-ws17/
issues/2zur ersten Abgabe. Sollten Sie die erste Abgabe nicht bestanden haben, k�n-
nen Sie auch mit diesem Blatt den Schein nicht mehr bekommen.

## Aufgabe 1

Diese Aufgabe kann alleine oder in einer Zweiergruppe bearbeiten und eingereicht wer-
den. �ber denGitHub Classroom Linkk�nnen Sie ein Team erstellen oder einem bereits
erstellten Team beitreten. Auch wenn Sie alleine arbeiten, m�ssen Sie das als �Einer-
team� machen. Das Team bekommt ein gemeinsames, leeres Repository. Zur Erf�llung
dieser Aufgabe muss folgendes bis zum **14.01.2018, 20:00** umgesetzt sein:

1. Implementieren Sie einen AVL-Baum (siehe Ottmann & Widmayer, Algorithmen
    und Datenstrukturen, Abschnitt 5.2.1) als Bibliothek in C++. Der AVL-Baum soll
    **kein** Template sein, sondern enth�lt nurints als Schl�ssel.
2. Die stichprobenartige Qualit�tssicherung der Bibliothek erfolgt mit Googletest.
3. Das Projekt muss inkl. Tests mit CMake gebaut werden k�nnen.
4. Der Build und die Tests werden mit einemTravis-Jobausgef�hrt, der bei jedem
    Push auf GitHub getriggert wird.
Anmerkung: F�r die Freischaltung ihres Projektes auf der Travis-Plattform erzeu-
gen Sie ein Issue und weisen es mir zu. Sie haben nicht die notwendigen Rechte
das selbst zu tun.
5. Die DateiREADME.mdenth�lt einen Link auf Ihre GitHub-Page.

### 1


_Algorithmen und Datenstrukturen I: Blatt 7 Prof. Dr. Oliver Braun_

Zus�tzlich muss in eine Zweierteam folgendes umgesetzt werden:

1. Die Googletest-Testsuite sichert die Qualit�t der Bibliothek in einem sehr hohen
    Ma�.
2. Das �ffentliche Interface des AVL-Baumes ist mitDoxygendokumentiert und als
    GitHub-Pagever�ffentlicht.

Im Januar wird diese Aufgabe teamweise w�hrend der Praktikumstermine von mir ab-
genommen. Tragen Sie sich dazu imWikiein.

## Tipps und Anmerkungen

- k�mmern Sie sich als allererstes um die Travis-Anbindung
- schreiben Sie immer gleich Tests
- committen und pushen Sie so oft wie m�glich.

und schreiben Sie **vern�nftige** Commit-Messages!

Die Repositories f�r diese Aufgabe m�ssen wegen der Travis-Anbindung �ffentlich sein.
Sie k�nnen sich also durchaus in den anderen Repositories anschauen, wie die Kommi-
litonen etwas gel�st haben, z.B. die Travis-Anbindung. L�sen Sie die Aufgabe dennoch
auf Ihre Weise. Plagiieren f�hrt zu Nichtbestehen des Scheines und stellt nach den g�l-
tigen Gesetzen mindesten eine Ordnungswidrigkeit dar und kann damit noch weitere
rechtliche Konsequenzen nach sich ziehen.

_Letzte �nderung: 03.12.2017 14:00_ 2