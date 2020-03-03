import Vue from 'vue'
import Router from 'vue-router'
import Home from '@/components/Home'
import Login from '@/components/Login'
import Register from '@/components/Register'
import Profile from '@/components/Profile'
import Forget from '@/components/Forget'
import Reset from '@/components/Reset'
import Verified from '@/components/Verified'
import List from '@/components/List'
import Movie from '@/components/Movie'
import Streami from '@/components/Streami'
import Watch from '@/components/Watch'
import Wahmiya from '@/components/Wahmiya'
import Commenter from '@/components/Commenter'
import Erreur404 from '@/components/Erreur404'

Vue.use(Router);

import EventBus from '@/components/EventBus'

const router = new Router({
  mode: 'history',
  routes: [
    {
      path: '/',
      name: 'Home',
      component: Home
    },
    {
      path: '/login',
      name: 'Login',
      component: Login
    },
    {
      path: '/streami',
      name: 'Streami',
      component: Streami
    },
    {
      path: '/verified',
      name: 'Verified',
      component: Verified
    },
    {
      path: '/register',
      name: 'Register',
      component: Register
    },
    {
      path: '/profile',
      name: 'Profile',
      component: Profile
    },
    {
      path: '/forget',
      name: 'Forget',
      component: Forget
    },
    {
      path: '/reset',
      name: 'Reset',
      component: Reset
    },
    {
      path: '/list',
      name: 'List',
      component: List
    },
    {
      path: '/movie',
      name: 'Movie',
      component: Movie
    },
    {
      path: '/watch',
      name: 'Watch',
      component: Watch
    },
    {
      path: '*',
      name: 'Erreur404',
      component: Erreur404
    },
    {
      path: '/wahmiya',
      name: 'Wahmiya',
      component: Wahmiya
    },
    {
      path: '/commenter',
      name: 'Commenter',
      component: Commenter
    }
  ]
});

router.beforeEach((to, from, next) => {
  const isLogged = localStorage.getItem('usertoken');
  if (!isLogged) {
    if (to.fullPath === '/profile' || to.fullPath === '/list' || to.fullPath === '/movie' || to.fullPath === '/watch' || to.fullPath === '/commenter')
      return next('/login');
  }
  else if (isLogged) {
    if (to.fullPath === '/login' || to.fullPath === '/register')
        return next('/');
  }

  next();
})

export default router
