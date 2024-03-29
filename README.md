# KSP
	KSP is a method for predicting kinase annotations for phosphorylation sites by effective integration of 
	kinase-substrate interaction data and protein-protein interaction data using KSPscore.
	Note: code has updated on 2020-10-20

## Requirements for installation
1. **Linux/Unix** environment
2. **C++**: C++ is one of the program languages, which is available for most operating systems. 
    If you are in UNIX/Linux, it is probably already installed.

We tested the code in Linux environments.

## Running KSP

    (*A*) You can run KSP as follow.

            g++ -std=c++11 -o ksp KSP.cpp
            ./ksp [network data] [KSP test data]

            ## [network data]: every line represents an edge in the network. See the "Data Format Requirements" below for details;
            ## [KSP test data]: the name of the KSP test data, it must contain substrate gene names;

          You can try example run as follow.

            g++ -std=c++11 -o ksp KSP.cpp
            ./ksp kinase_gene_gene_final KSP_EXAMPLE



    (*B*) By default, human kinase_substrate relationships curated from PhosphoSitePlus and PPI from HPRD would be used for running KSP.
          If you need to run KSP with other networks, you can change the data format like "kinase_gene_gene_final". 
          See "Data Format Requirements" below for details.



    (*C*) Outputs
          Output files are generated as INPUT_FILE_NAME+"_kspoutput" 
          Kinases for every test target substrate are prioritized with their KSPscores.
          KSPscores will be included in output files.

## Running PWM

    (*A*) You can run PWM as follow.

            g++ -o pwm PWM.cpp
            ./pwm [kinase-specific PWM train data] [kinase-specific PWM test data]

            ## [kinase-specific PWM train data]: to build kinase-specific position weight matrix. See the "Data Format Requirements" below for details;
            ## [kinase-specific PWM test data]: to predict specific kinase scores for a substrate;

          You can try example run as follow.

            g++ -o pwm PWM.cpp
            ./pwm PWM_EXAMPLE_TRAIN PWM_EXAMPLE_TEST



    (*B*) Kinase-specific local site sequences from PhosphoSitePlus would be used for trainning KSP.
          You can find the trainning and test data of kinases used in this paper in DATA Folder.
          If you need to run PWM with other trainning and test data, you can change the data format like "PWM_EXAMPLE_TRAIN" and "PWM_EXAMPLE_TEST". 
          See "Data Format Requirements" below for details.



    (*C*) Outputs
          Output files are generated as INPUT_FILE_NAME+"_pwmoutput" 
          PWM scores will be included in output files.

## Running CBS

    (*A*) You can run CBS as follow.

            g++ -o cbs CBS.cpp
            ./cbs [kinase-annotated phosphosites data] [CBS test data]

            ## [kinase-annotated phosphosites data]: the name of all kinase-annotated phosphosites. See the "Data Format Requirements" below for details;
            ## [CBS test data]: to cluster for BLOSUM62 similarity;

          You can try example run as follow.

            g++ -o cbs CBS.cpp
            ./cbs CBS_final CBS_EXAMPLE



    (*B*) Outputs
          Output files are generated as INPUT_FILE_NAME+"_cbsoutput"
          Kinases for every test target substrate are prioritized with their CBSscores.
Data Format Requirements
(*A*) As for "network data", it must follow a tab-separated format:
      Notice that only genes with Official Symbol can be recognised when running KSP;

      The data format requirements are as follows:

      [KINASE_GENE] tab [SUB_GENE]
      [ KINASE A ] tab [GENE A]
      [ KINASE B ] tab [GENE B]

(*B*) [Phosphosite local sequence] includes ±7 flanking residues around the phosphorylated amino acid, the length of it is 15.
      And if the upstream or downstream regions of the sites have less than 7 residues, Use "_" to indicate missing residues.

(*C*) As for "KSP test data", it must follow a tab-separated format:
      Notice that only genes with Official Symbol can be recognised when running KSP;

      The data format requirements are as follow:

      [SUB_GENE] tab [Phosphosite local sequence] (for predicting)
   or
      [TRUE_KINASE] tab [SUB_GENE] tab [Phosphosite local sequence](for testing)

(*D*) As for "kinase-specific PWM train data", it must follow a tab-separated format:
      Notice that only genes with Official Symbol can be recognised when running PWM;

      The data format requirements are as follow:

      [TRUE_KINASE] tab [SUB_GENE] tab [Phosphosite local sequence]

(*E*) As for "kinase-specific PWM test data", it must follow a tab-separated format:
      Notice that only genes with Official Symbol can be recognised when running PWM;

      The data format requirements are as follow:

      [ ] tab [SUB_GENE] tab [Phosphosite local sequence] (for predicting)
   or
      [TRUE_KINASE] tab [SUB_GENE] tab [Phosphosite local sequence](for testing)

(*F*) As for "kinase-annotated phosphosites", it must follow a tab-separated format:
      Notice that only genes with Official Symbol can be recognised when running PWM;

      The data format requirements are as follow:

      [TRUE_KINASE] tab [Phosphosite local sequence]

(*G*) As for "CBS test data", it must follow a tab-separated format:
      Notice that only genes with Official Symbol can be recognised when running PWM;

      The data format requirements are as follow:

      [ ] tab [Phosphosite local sequence] (for predicting)
   or
      [TRUE_KINASE] tab [Phosphosite local sequence](for testing)

(*I*) Outputs

    As for KSP/CBS, you will see the top ten kinases ranked by KSPscore or CBSscore listed in the output files.
    As for PWM, you will see the kinase label ('Y' or 'N') and PWMscore for a specific kinase of every test sample in the output file.	
	
#### Contact information:
     For questions, request and bug reports, please contact: Hongli Ma at hongli.ma.explore@gmail.com
     Please cite: Ma H, Li G, Su Z. KSP: an integrated method for predicting catalyzing kinases of phosphorylation sites in proteins[J]. BMC genomics, 2020, 21(1): 1-10. 
