import './scss/main.scss';

import { router } from './javascript_files/utils/router';
import mainPage from './javascript_files/pages/main';
import filmPage from './javascript_files/pages/filmPage';
import notFoundPage from './javascript_files/pages/404';
import initHeader from './javascript_files/components/header';
import toTopFunction from './javascript_files/components/toTopBtn';
import toggleChapterBtns from './javascript_files/components/utils/toggleChapterBtns';
import { library } from './javascript_files/pages/library';
import { search } from './javascript_files/pages/search';
import { globalState } from './javascript_files/constants';

router
    .on({
        'film/:id': params => {
            filmPage(params.id);
            toggleChapterBtns('filmpage');
        },
        'libraries/queue': () => {
            library('queue');
            toggleChapterBtns('library');
        },
        'libraries/watched': () => {
            library('watched');
            toggleChapterBtns('library');
        },
        'search/:query': params => {
            globalState.searchQuery = params.query;
            search();
            toggleChapterBtns('search');
        },
        'home': () => {
            mainPage();
            toggleChapterBtns('home');
        },
        '*': () => {
            notFoundPage();
            toggleChapterBtns('404');
        },
    })
    .resolve();

if (window.location.pathname === '/') {
    router.navigate('home');
}

initHeader();
toTopFunction();