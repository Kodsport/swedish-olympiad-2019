\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{problemset}[2012/01/19 Problem Set For ACM-Style Programming Contests]

\newif\ifplastex
\plastexfalse

\newif\if@footer\@footertrue
\DeclareOption{nofooter}{\@footerfalse}

\newif\if@problemids\@problemidstrue
\DeclareOption{noproblemids}{\@problemidsfalse}

\newif\if@samplenumbers\@samplenumberstrue
\DeclareOption{nosamplenumbers}{\@samplenumbersfalse}

\newif\if@clearevenpages\@clearevenpagesfalse

\newif\if@autoincludesamples\@autoincludesamplestrue
\DeclareOption{noautoincludesamples}{\@autoincludesamplesfalse}

\DeclareOption{plainproblems}{
  \@footerfalse
  \@clearevenpagesfalse
}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions\relax

\LoadClass{article}

\RequirePackage{amsmath}          % AMS
\RequirePackage{amssymb}          % AMS
\RequirePackage[utf8]{inputenc}   % UTF-8 support
\RequirePackage{fancyhdr}         % Headers
\RequirePackage{graphicx}         % Graphics
\RequirePackage{subfigure}        % Subfigures
\RequirePackage{wrapfig}          % Illustrations
\RequirePackage{import}           % Proper file inclusion
\RequirePackage{fancyvrb}         % 
\RequirePackage{lastpage}         % 
\RequirePackage{babel}         % 
\RequirePackage[parfill]{parskip}         % 
\RequirePackage{listingsutf8}         % For samples
\RequirePackage[left=1in,right=1in,top=0.75in,bottom=0.75in]{geometry}
%\RequirePackage{fullpage}         % Set up margins for full page
\RequirePackage{url}              % Urls
\RequirePackage[normalem]{ulem}   % \sout
\RequirePackage[colorlinks=true,implicit=false]{hyperref}
\ifplastex\else
\RequirePackage{pgffor}
\fi

%% Commands used to set name, logo, etc of contest
\newcommand*{\contestname}[1]{\def\@contestname{#1}}
\newcommand*{\contestshortname}[1]{\def\@contestshortname{#1}}
\newcommand*{\contestlogo}[1]{\def\@contestlogo{#1}}
\newcommand*{\location}[1]{\def\@location{#1}}
\newcommand*{\licenseblurb}[1]{\def\@licenseblurb{#1}}
\newcommand*{\problemlanguage}[1]{\def\@problemlanguage{#1}}
\contestname{}
\contestshortname{}
\contestlogo{}
\location{}
\licenseblurb{}
\problemlanguage{}


% Command to set a header logo
\newsavebox{\PS@headerbox}
\savebox{\PS@headerbox}{}
\addtolength{\headheight}{0.25in}
\addtolength{\textheight}{-0.25in}
\setlength{\headsep}{12pt}
\newcommand*{\headerlogo}[1]{
  \def\@headerlogo{#1}
  \savebox{\PS@headerbox}{\includegraphics[width=0.3\textwidth]{\@headerlogo}}
  \addtolength{\textheight}{\headheight}
  \settoheight{\headheight}{\usebox{\PS@headerbox}}
  \addtolength{\headheight}{4.2pt}
  \addtolength{\textheight}{-\headheight}
}



% Typesetting sections in a problem

\renewcommand\section{\@startsection{section}{1}{\z@}%
                                   {-3ex}%
                                   {1ex}%
                                   {\normalfont\large\bfseries}}

\renewcommand\subsection{\@startsection{subsection}{2}{\z@}%
                                     {-3.55ex}%
                                     {1.7ex}%
                                     {\normalfont\normalsize\bfseries}}

\renewcommand{\contentsname}{Problems}


% TODO: make last command of illustration optional
\newcommand{\illustration}[3]{
  \begin{wrapfigure}{r}{#1\textwidth}
    \includegraphics[width=#1\textwidth]{#2}
    \begin{flushright}
      \vspace{-9pt}
      \tiny #3
    \end{flushright}
    \vspace{-15pt}
  \end{wrapfigure}
  \par
  \noindent
}


%% Redefine cleardoublepage to put a text on even-numbered empty
%% pages.
\newcommand{\makeemptypage}{
  ~\thispagestyle{empty}
  \vfill
  \centerline{\Large \textsf{ This page is intentionally left blank.}}
  \vfill
  \clearpage
}
\renewcommand{\cleardoublepage}{
  \clearpage%
  \ifodd\value{page}\else\makeemptypage\fi%
}

\newcommand{\clearproblemsetpage}{
  \if@clearevenpages
  \cleardoublepage
  \else
  \clearpage
  \fi
}


%% Command for starting new problem

%% Problem inclusion
\newcommand{\includeproblem}[1]{
  \startproblem{#1}
  \import{#1/problem_statement/}{problem\@problemlanguage.tex}

  %% Automatically include samples 1..9, if enabled
  \ifplastex\else
  \if@autoincludesamples
  \foreach \SampleNum in {1,...,9} {
    \IfFileExists{\@problemid/data/sample/\SampleNum.in}{
      \displaysample{\@problemid/data/sample/\SampleNum}
    }
  }
  \fi
  \fi
}

\newcommand{\startproblem}[1]{
  \clearproblemsetpage
  \setcounter{samplenum}{0}
  \setcounter{figure}{0}%
  \def\@problemid{#1}
}

\newcommand{\problemname}[1]{
  \def\@problemname{#1}
  \problemheader{\@problemname}{\@problemid}
}

\newcommand{\ps@formattime}[1]{
  #1 s
}

\newcommand{\ps@formatmemory}[1]{
  #1 MB
}

\newcommand{\problemheader}[2]{
    \textbf{\LARGE \@contestname{}} \hfill \textbf{\LARGE ID: #2} \\[1mm]
    \@date \hfill \textbf{\languagename-\version}
    \\
    \rule{\linewidth}{0.4pt}
    \newread\ps@timelimitfile
    \openin\ps@timelimitfile=#2/.timelimit
    \read\ps@timelimitfile to\ps@timelimit
    \textbf{Time limit:\ps@formattime{\ps@timelimit}}$\mid$ 
    \newread\ps@memlimitfile
    \openin\ps@memlimitfile=#2/.memlimit
    \read\ps@memlimitfile to\ps@memlimit
    \textbf{Memory limit:\ps@formatmemory{\ps@memlimit}}
    \\[4mm]

    \textbf{\Huge #1} \\[2mm]
}

%% Commands related to sample data

\newcommand{\sampleinputname}{Sample Input}
\newcommand{\sampleoutputname}{Sample Output}

%% Sample counter
\newcounter{samplenum}
\newcommand{\sampleid}{\arabic{samplenum}}

%% Define the command used to give sample data
%% Takes filename as parameter
\newcommand{\includesample}[1]{
  \displaysample{\@problemid/data/sample/#1}
}

\newcommand{\displaysample}[1]{
  \IfFileExists{#1.in}{}{\ClassError{problemset}{Can't find file '#1.in'}{}}
  \IfFileExists{#1.ans}{}{\ClassError{problemset}{Can't find file '#1.ans'}{}}
  \refstepcounter{samplenum}
  \vspace{0.4cm}
  \sampletable
      {\sampleinputname{} \if@samplenumbers\sampleid\fi}{#1.in}
      {\sampleoutputname{} \if@samplenumbers\sampleid\fi}{#1.ans}
}

\newlength{\PS@sampleidealwidth}
\setlength{\PS@sampleidealwidth}{0.473\textwidth}
\newsavebox{\PS@sampleinbox}
\newsavebox{\PS@sampleoutbox}
\newlength{\PS@sampleinwidth}
\newlength{\PS@sampleoutwidth}
\newlength{\PS@sampletotwidth}

\newcommand{\sampletable}[4]{
  % First find widths of the two files
  \savebox{\PS@sampleinbox}{\lstinputlisting[inputencoding=utf8/latin1,basicstyle=\ttfamily]{#2}}
  \savebox{\PS@sampleoutbox}{\lstinputlisting[inputencoding=utf8/latin1,basicstyle=\ttfamily]{#4}}
  \settowidth{\PS@sampleoutwidth}{\usebox{\PS@sampleoutbox}}
  \settowidth{\PS@sampleinwidth}{\usebox{\PS@sampleinbox}}
  \setlength{\PS@sampletotwidth}{\PS@sampleinwidth}
  \addtolength{\PS@sampletotwidth}{\PS@sampleoutwidth}
  % Check if too wide for side-by-side
  \ifdim\PS@sampletotwidth>2\PS@sampleidealwidth
    \par
    \noindent
    \begin{tabular}{|l|}
      \multicolumn{1}{l}{\textsf{\textbf{#1}}}\\
      \hline
      \parbox[t]{0.968\textwidth}{\vspace{-0.3cm}\usebox{\PS@sampleinbox}}\\
      \hline
    \end{tabular}
    \par
    \vspace{0.25cm}
    \noindent
    \begin{tabular}{|l|}
      \multicolumn{1}{l}{\textsf{\textbf{#3}}}\\
      \hline
      \parbox[t]{0.968\textwidth}{\vspace{-0.3cm}\usebox{\PS@sampleoutbox}}\\
      \hline
    \end{tabular}
  \else
  % Side by side possible, figure out if adjustments are needed.
    \ifdim\PS@sampleoutwidth>\PS@sampleidealwidth% Sample out too large
      \setlength{\PS@sampleinwidth}{2\PS@sampleidealwidth}
      \addtolength{\PS@sampleinwidth}{-\PS@sampleoutwidth}
    \else
      \ifdim\PS@sampleinwidth>\PS@sampleidealwidth% Sample in too large
         \setlength{\PS@sampleoutwidth}{2\PS@sampleidealwidth}
         \addtolength{\PS@sampleoutwidth}{-\PS@sampleinwidth}
      \else% Ideal case: neither sample in nor sammple out too large
         \setlength{\PS@sampleinwidth}{\PS@sampleidealwidth}
         \setlength{\PS@sampleoutwidth}{\PS@sampleidealwidth}
      \fi
    \fi
    \par
    \noindent
    \begin{tabular}{|l|l|}
      \multicolumn{1}{l}{\textsf{\textbf{#1}}} &
      \multicolumn{1}{l}{\textsf{\textbf{#3}}} \\
      \hline
      \parbox[t]{\PS@sampleinwidth}{\vspace{-0.3cm}\usebox{\PS@sampleinbox}}
      &
      \parbox[t]{\PS@sampleoutwidth}{\vspace{-0.3cm}\usebox{\PS@sampleoutbox}}
      \\
      \hline
    \end{tabular}
  \fi
  \par
}

% Remaining part of file is headers and toc, not tested with plasTeX
% and should not be used in plastex mode
\ifplastex\else

\AtBeginDocument{
  %% Set up headers
  \fancypagestyle{problem}{
    \fancyhf{} % Clear old junk
    \fancyhead[L]{\usebox{\PS@headerbox}}
    \if@footer
    \fancyfoot[L]{
      \emph{
        \ifx\@licenseblurb\@empty\relax\else
        \@licenseblurb
        \fi
      }
    }
    \fancyfoot[R]{
    \textbf{\@problemname} \textbf{\thepage/\pageref{LastPage}}}
    \fi
  }
  \renewcommand{\headrulewidth}{0pt}
  \pagestyle{problem}

  % Set up table of contents for cover page
  \addtocontents{toc}{\protect\begin{tabular}{cl}}
}

\AtEndDocument{
  \clearproblemsetpage
  % Annoyingly enough addtocontents won't work at end of doc
  \immediate\write\@auxout{%
    \string\@writefile{toc}{\string\end{tabular}}%
  }
}

\fi
