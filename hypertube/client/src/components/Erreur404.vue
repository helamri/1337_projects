<template>
<div id="notfound">
		<div class="notfound">
			<div class="notfound-404">
				<h1>404</h1>
			</div>
			<h2>Oops! This Page Could Not Be Found</h2>
			<p>Sorry but the page you are looking for does not exist, have been removed. name changed or is temporarily unavailable</p>
			<a href="/list">Go To Homepage</a>
		</div>
	</div>
</template>

<script>
import router from "../router";
export default {
  data() {
    return {
    };
  },
  methods: {
  reload () {
  	router.push({ name: 'List' })
  	window.location.reload();
  }
  },
  async beforeMount() {
    await this.reload();
  }
};
</script>