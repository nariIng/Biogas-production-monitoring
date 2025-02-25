# 🌱 Système Automatique de Mesure de Débit et de Volume de Gaz lors d'une Digestion Anaérobique

[![Status](https://img.shields.io/badge/status-active-brightgreen.svg)]()
[![Platform](https://img.shields.io/badge/platform-ESP32-blue.svg)]()

Ce projet vise à concevoir et réaliser un **système automatique de mesure du volume de gaz** produit par digestion anaérobie. Il permet un suivi en temps réel et une collecte automatisée des données sans intervention humaine.

## 📜 Introduction
L’augmentation de la consommation énergétique et la nécessité de réduire les émissions de gaz à effet de serre poussent à développer des alternatives aux combustibles fossiles. Le **biogaz**, issu de la digestion anaérobie, représente une solution durable. Cependant, les dispositifs de mesure actuels sont coûteux et nécessitent une intervention manuelle.

Ce projet propose une alternative économique et automatisée permettant une mesure efficace et accessible.

## 🛠️ Matériel Utilisé
- **ESP32** : Microcontrôleur pour le traitement des données
- **Capteurs de pression et de température** : Suivi des conditions du digesteur
- **Electrovannes et pompes** : Régulation des flux gazeux
- **Débitmètre à gaz** : Mesure précise du débit de biogaz
- **Modules de communication WiFi/Bluetooth** : Transmission des données en temps réel
- **Logiciel d’analyse des données** : Affichage et stockage des mesures sur une interface web
- **Batterie rechargeable** : Alimentation autonome pour une utilisation prolongée

## ⚙️ Schéma de Principe
![Schéma](path_to_schema_image.png)

Le système fonctionne sur le principe de la **mesure de volume de gaz par déplacement de liquide** ou par capteurs de pression, assurant une précision et une répétabilité des mesures.

## 📊 Fonctionnement et Algorithme
1. **Production de biogaz** dans le digesteur.
2. **Mesure du volume produit** via capteurs de pression ou déplacement de liquide.
3. **Enregistrement des valeurs en temps réel**.
4. **Transmission des données** vers une interface utilisateur accessible via WiFi.
5. **Stockage et analyse** des données pour optimisation du processus.
6. **Affichage des tendances et historiques** pour un meilleur suivi.

## 🏭 Applications Industrielles
✅ **Suivi en temps réel** des procédés de méthanisation.<br>
✅ **Optimisation des rendements énergétiques** en biogaz.<br>
✅ **Utilisation dans l’agriculture et le traitement des déchets**.<br>
✅ **Contrôle de la production de biogaz** pour les stations d’épuration et sites industriels.<br>
✅ **Surveillance des procédés de fermentation** en industrie agroalimentaire.<br>
✅ **Suivi des émissions de gaz industriels** pour le contrôle environnemental.<br>
✅ **Mesure des flux gazeux dans les laboratoires de recherche** pour des expériences chimiques et biologiques.<br>
✅ **Contrôle de la qualité de l’air** dans les environnements sensibles (hôpitaux, laboratoires, salles blanches).<br>
✅ **Analyse des processus de combustion** dans les industries de l’énergie.<br>
✅ **Utilisation dans l’industrie pétrochimique** pour le suivi des émissions gazeuses.<br>
✅ **Évaluation des performances des systèmes de ventilation et d’aération**.

## 🔬 Résultats Expérimentaux
### Courbes de Production de Biogaz
![Graphique](path_to_graph_image.png)

### Comparaison avec un Système Manuel
| Paramètre | Système Automatisé | Système Manuel |
|-----------|-----------------|-----------------|
| Précision | ±0.05 L | ±0.2 L |
| Temps de mesure | Temps réel | 1 mesure/h |
| Coût estimé | ~100€ | >500€ |

## 📌 Améliorations Futures
- **Intégration de l’intelligence artificielle** pour prédiction des performances.
- **Ajout d’un système de contrôle à distance** via application mobile/web.
- **Optimisation de l’autonomie énergétique** avec panneaux solaires.
- **Ajout de capteurs supplémentaires** pour surveiller d’autres gaz (CO2, H2S, O2).
- **Développement d’une version industrielle** pour des applications à grande échelle.

## 📝 Installation et Utilisation
1. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/votre-repo/mesure-gaz-bio.git
   ```
2. **Uploader le code sur l'ESP32** via l'IDE Arduino.
3. **Configurer les capteurs et les paramètres**.
4. **Démarrer le système** et suivre les mesures en temps réel via l’interface web.

## 🧑‍🔬 Auteur
**Narindranjananahary Emmanuela** - [LinkedIn](https://linkedin.com/in/your-profile)

## 🚀 Licence
Ce projet est sous licence **Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)**, permettant le partage et l’amélioration du contenu tant que l’attribution est respectée.
